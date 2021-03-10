/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <nvu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:26:39 by nvu               #+#    #+#             */
/*   Updated: 2021/03/10 09:26:40 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
