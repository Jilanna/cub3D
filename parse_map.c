/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <nvu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:21:13 by nvu               #+#    #+#             */
/*   Updated: 2021/03/10 13:13:28 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

t_list  *put_map_chain(int fd)
{
    char    *line;
    t_list  *begin;
    int     out;
    t_list  *new;

    out = 1;
    begin = NULL;
    while (out > 0)
    {
        out = get_next_line(fd, &line);
        if (out < 0)
        {
            ft_lstclear(&begin, free);
            break ;
        }
        new = ft_lstnew(ft_strdup(line));
        ft_lstadd_back(&begin, new);
        free(line);
        if (new == NULL)
        {
            ft_lstclear(&begin, free);
            break ;
        }
    }
    return (begin);
}

int		ft_lst_lenmax(t_list *lst)
{
    int len;
    int len_max;

    len_max = 0;
	if (!lst)
		return (0);
	while (lst->next)
	{
        len = ft_strlen(lst->content);
        if (len > len_max)
            len_max = len;
		lst = lst->next;
	}
	len = ft_strlen(lst->content);
    if (len > len_max)
        len_max = len;
    return (len_max);
}

int    free_map_tab(t_params *params, t_list **lst, int i)
{
    int k;

    k = i;
    while (i >= 0)
    {
        free(params->map[i]);
        i--;
    }
    if (k != -2)
        free(params->map);
    ft_lstclear(lst, free);
    return (-1);
}

int put_map_tab(t_params *params, int hight, int width, t_list *lst)
{
    int     i;
    int     j;
    t_list  **begin;

    begin = &lst;
    params->map = malloc(sizeof(char*) * hight);
    if (params->map == NULL)
        return (free_map_tab(params, begin, -2));
    i = 0;
    while (i <= hight)
    {
        params->map[i] = malloc(sizeof(char) * (width + 1));
        if (params->map[i] == NULL)
            return (free_map_tab(params, begin, i - 1));
        j = -1;
        while (lst->content[++j] != '\0')
            params->map[i][j] = lst->content[j];
        params->map[i][j] = '\0';
        lst = lst->next;
        i++;
    }
    ft_lstclear(&lst, free);
    return (0);
}

int parse_map(int fd, t_params *params)
{
    t_list  *begin;
    int     out;

    begin = put_map_chain(fd);
    params->hight = ft_lstsize(begin);
    params->width = ft_lst_lenmax(begin);
    out = put_map_tab(params, params->hight, params->width, begin);
    if (out == -1)
        return (-1);
    out = test_map(params);
    return (out);
}