/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:25:42 by nvu               #+#    #+#             */
/*   Updated: 2020/11/27 16:04:47 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
