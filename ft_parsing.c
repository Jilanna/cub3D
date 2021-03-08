#include "cube.h"
#include "libft.h"

t_params    *init_params(void)
{
    t_params    *params;

    params = malloc(sizeof(t_params));
    if (params == NULL)
        return (params);
    params->save = 0;
    params->taillex = -1;
    params->tailley = -1;
    params->no = NULL;
    params->so = NULL;
    params->we = NULL;
    params->ea = NULL;
    params->s = NULL;
    params->f[0] = -1;
    params->f[1] = -1;
    params->f[2] = -1;
    params->c[0] = -1;
    params->c[1] = -1;
    params->c[2] = -1;
    return (params);
}

int test_input(int ac, char **av)
{
    int i;

    if (ac < 2)
        return (-1);
    i = 0;
    while (av[1][i])
        i++;
    if (!(i >= 6 || (av[1][i - 1] == 'b' && av[1][i - 2] == 'u'
    && av[1][i - 3] == 'c' && av[1][i - 4] == '.')))
        return (-1);
    return (0);
}

char    *is_path_right(char *line)
{
    int     len;
    char    *path;

    len = ft_strlen(line);
    if (len < 4)
        return (NULL);
    if (!((line[0] == 'N' && line[1] == 'O' && line[2] == ' ') ||
    (line[0] == 'S' && line[1] == 'O' && line[2] == ' ') ||
    (line[0] == 'W' && line[1] == 'E' && line[2] == ' ') ||
    (line[0] == 'E' && line[1] == 'A' && line[2] == ' ') ||
    (line[0] == 'S' && line[1] == ' ')))
        return (NULL);
    if (line[0] == 'S' && line[1] == ' ')
        path = ft_substr(line, 3, len);
    else
        path = ft_substr(line, 4, len);
    len = open(path, O_RDONLY);
    if (len == -1)
        return (NULL);
    else
        close(len);
    return (path);
}

int get_path(char *line, t_params *params)
{
    char    *path;

    path = is_path_right(line);
    if (path == NULL)
        return (-1);
    if (line[0] == 'N' && params->no == NULL)
        params->no = path;
    else if (line[0] == 'E' && params->ea == NULL)
        params->ea = path;
    else if (line[1] == 'O' && params->so == NULL)
        params->so = path;
    else if (line[0] == 'W' && params->we == NULL)
        params->we = path;
    else if (line[0] == 'S' && params->s == NULL)
        params->s = path;
    else
        return (-1);
}

int get_size(char *line, int *i, int len)
{
    int     j;
    char    *size;

    j = (*i);
    while (j < len && line[j] >= '0' && line[j] <= '9')
        j++;
    size = malloc(sizeof(char) * (j + 1));
    if (size == NULL)
        return (-1);
    j = (*i);
    while ((*i) < len && line[*i] >= '0' && line[*i] <= '9')
    {
        size[(*i) - j] = line[*i];
        (*i)++;
    }
    size[(*i) - j] = '\0';
    j = ft_atoi(size);
    free(size);
    return (j);
}

int get_resolution(char *line, t_params *params)
{
    int     i;
    int     len;
    int     temp;

    len = ft_strlen(line);
    if (len < 5)
        return (-1);
    if (line[1] != ' ')
        return (-1);
    i = 3;
    temp = get_size(line, &i, len);
    if (temp == -1 || params->sizex != -1)
        return (-1);
    params->sizex = temp;
    if (line[i] != ' ')
        return(-1);
    i++;
    temp = get_size(line, &i, len);
    if (temp == -1 || params->sizey != -1)
        return (-1);
    params->sizey = temp;
    return (0);
}

int get_color(char *line, int *rgb)
{
    int temp;
    int i;

    if (line[1] != ' ')
        return (-1);
    i = 2;
    temp = get_size(line, &i, len);
    if (temp < 0 || temp > 255 || rgb[0] != -1)
        return (-1);
    rgb[0] = temp;
    if (line[i++] != ',')
        return(-1);
    temp = get_size(line, &i, len);
    if (temp < 0 || temp > 255 || rgb[1] != -1)
        return (-1);
    rgb[1] = temp;
    if (line[i++] != ',')
        return(-1);
    temp = get_size(line, &i, len);
    if (temp < 0 || temp > 255 || rgb[2] != -1)
        return (-1);
    rgb[2] = temp;
    return (0);
}

int parse_params(int fd, t_params *params)
{
    char    *line;
    int     out;

    out = 1;
    while (out > 0)
    {
        out = get_next_line(fd, &line);
        if (out < 0)
            break ;
        if (line[0] == 'N' || line[0] == 'E' || line[0] == 'S' || line[0] == 'W')
            out = get_path(line, params);
        else if (line[0] == 'R')
            out = get_resolution(line, params);
        else if (line[0] == 'C')
            out = get_color(line, params->c);
        else if (line[0] == 'F')
            out = get_color(line, params->f);
        else if (line[0] == '\n')
            continue ;
        else
            break ;
    }
}

int ft_parsing(int ac, char **av)
{
    t_params   *params;
    int         fd;

    fd = test_input(ac, av);
    if (fd == -1)
        return (-1);
    params = init_params();
    if (params == NULL)
        return (-1);
    if (ac >= 3 && ft_strcmp("--save", av[2]) == 0)
        params->save = 1;
    fd = open(av[1], O_RDONLY);
    if (fd != -1)
        parse_params(fd, params);
    
    return (0);
}