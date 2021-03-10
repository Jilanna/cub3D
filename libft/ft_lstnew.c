/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <nvu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:26:29 by nvu               #+#    #+#             */
/*   Updated: 2021/03/10 09:26:31 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list		*newelem;

	newelem = malloc(sizeof(t_list));
	if (newelem == NULL)
		return (NULL);
	newelem->content = content;
	newelem->next = NULL;
	return (newelem);
}
