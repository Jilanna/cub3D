/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <nvu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:21:47 by nvu               #+#    #+#             */
/*   Updated: 2021/03/10 09:21:49 by nvu              ###   ########lyon.fr   */
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
