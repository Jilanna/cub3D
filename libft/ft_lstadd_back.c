/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:09:18 by nvu               #+#    #+#             */
/*   Updated: 2020/12/02 14:49:02 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **alst, t_list *n)
{
	t_list		*temp;

	if ((*alst) == NULL)
	{
		(*alst) = n;
		return ;
	}
	temp = (*alst);
	while (temp->next)
		temp = temp->next;
	temp->next = n;
}
