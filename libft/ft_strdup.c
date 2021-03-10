/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <nvu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:25:48 by nvu               #+#    #+#             */
/*   Updated: 2021/03/10 09:25:49 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;
	int		src_len;

	src_len = ft_strlen(src);
	ptr = NULL;
	ptr = malloc(sizeof(char) * src_len + 1);
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (i < src_len)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}