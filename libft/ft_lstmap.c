/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:04:40 by nvu               #+#    #+#             */
/*   Updated: 2020/12/11 12:52:23 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int		ft_lstpush_back(t_list *begin, void *content)
{
	t_list		*new;
	t_list		*temp;

	temp = begin;
	new = ft_lstnew(content);
	if (new == NULL)
		return (1);
	while (begin->next)
		begin = begin->next;
	begin->next = new;
	begin = temp;
	return (0);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list		*nlst;

	if (!lst || !f)
		return (NULL);
	if (!(nlst = ft_lstnew(f(lst->content))))
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (ft_lstpush_back(nlst, f(lst->content)))
			ft_lstclear(&nlst, del);
	}
	return (nlst);
}
