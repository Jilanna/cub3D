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

int put_map_tab(t_params *params, int hight, int width, t_list *lst)
{
    int i;
    int j;

    params->map = malloc(sizeof(char*) * hight);
    if (params->map == NULL)
        return (-1);
    i = 0;
    while (i <= hight)
    {
        params->map[i] = malloc(sizeof(char) * (width + 1));
        if (params->map[i] == NULL)
            return (-1);
        j = -1;
        while (lst->content[++j] != '\0')
            params->map[i][j] = lst->content[j];
        params->map[i][j] = '\0';
        lst = lst->next;
        i++;
    }
    return (0);
}

int parse_map(int fd, t_params *params)
{
    t_list  *begin;
    int     out;

    begin = put_map_chain(fd);
    out = put_map_tab(params, ft_lstsize(begin), ft_lst_lenmax(begin), begin);
    printf("%p", begin);
}