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
		return ;
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

int parse_map(int fd, t_params *params)
{
    t_list  *begin;
    int     hight;
    int     width;


    begin = put_map_chain(fd);
    hight = ft_lstsize(begin);
    width = ft_lst_lenmax(begin);
    



}