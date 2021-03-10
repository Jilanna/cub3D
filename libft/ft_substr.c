/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <nvu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:25:32 by nvu               #+#    #+#             */
/*   Updated: 2021/03/10 09:25:35 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, int start, int len)
{
	int		i;
	char	*ptr;
	int		len;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (start > len - 1)
		return (ft_strdup(""));
	len = len - start;
	if (len > len)
		len = len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[start + i] != 0 && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}