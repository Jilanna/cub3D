/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <nvu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:25:03 by nvu               #+#    #+#             */
/*   Updated: 2021/03/10 09:25:06 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
#include "../includes/libft.h"

char    *is_path_right(char *line)
{
    int     len;
    char    *path;
    int     i;

    len = ft_strlen(line);
    if (len < 4)
        return (NULL);
    if (!((line[0] == 'N' && line[1] == 'O' && line[2] == ' ') ||
    (line[0] == 'S' && line[1] == 'O' && line[2] == ' ') ||
    (line[0] == 'W' && line[1] == 'E' && line[2] == ' ') ||
    (line[0] == 'E' && line[1] == 'A' && line[2] == ' ') ||
    (line[0] == 'S' && line[1] == ' ')))
        return (NULL);
    i = 2;
    while (line[i] == ' ')
        i++;
    path = ft_substr(line, i, len);
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
    i = 1;
    while (line[i] == ' ')
        i++;
    temp = get_size(line, &i, len);
    if (temp == -1 || params->sizex != -1)
        return (-1);
    params->sizex = temp;
    if (line[i] != ' ')
        return(-1);
    while (line[i] == ' ')
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
    int len;

    i = 1;
    if (line[i] != ' ')
        return (-1);
    while (line[i] == ' ')
        i++;
    len = ft_strlen(line);
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