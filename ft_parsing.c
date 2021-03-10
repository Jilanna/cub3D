/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <nvu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:21:17 by nvu               #+#    #+#             */
/*   Updated: 2021/03/10 09:21:27 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

t_params    *init_params(void)
{
    t_params    *params;

    params = malloc(sizeof(t_params));
    if (params == NULL)
        return (params);
    params->sizex = -1;
    params->sizey = -1;
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

int are_params_right(t_params *params)
{
    if (params->sizex == -1 || params->sizey == -1 || params->no == NULL
    || params->so == NULL || params->we == NULL || params->ea == NULL
    || params->s == NULL || params->f[0] == -1 || params->f[1] == -1
    || params->f[2] == -1 || params->c[0] == -1 || params->c[1] == -1
    || params->c[2] == -1)
        return (-1);
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
        free(line);
    }
    out = are_params_right(params);
    return (out);
}

int ft_parsing(int ac, char **av)
{
    t_params   *params;
    int         fd;
    int         out;

    fd = test_input(ac, av);
    if (fd == -1)
        return (-1);
    params = init_params();
    if (params == NULL)
        return (-1);
    if (ac >= 3 && ft_strcmp("--save", av[2]) == 0)
        params->save = 1;
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (-1);
    out = parse_params(fd, params);
    out = parse_map(fd, params);
    return (0);
}