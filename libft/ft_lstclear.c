/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:24:50 by nvu               #+#    #+#             */
/*   Updated: 2020/12/02 11:46:41 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*temp;
	t_list		**temp_first;

	temp_first = lst;
	while ((*lst)->next)
	{
		temp = (*lst);
		(*lst) = (*lst)->next;
		del(temp->content);
		free(temp);
	}
	del((*lst)->content);
	free(*lst);
	*temp_first = NULL;
}
