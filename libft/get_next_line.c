/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <nvu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:25:19 by nvu               #+#    #+#             */
/*   Updated: 2021/03/10 09:25:20 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_str_add_char(char *s, char c)
{
	char	*str;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = 0;
	while (str && str[len] != '\0')
		len++;
	str = malloc(sizeof(char) * (len + 2));
	if (str == NULL)
	{
		free(s);
		return (NULL);
	}
	i = -1;
	while (i++ < len)
		str[i] = s[i];
	str[i] = c;
	str[len + 2] = '\0';
	free(s);
	return (str);
}

int	ft_read_one_line(int fd, int *one, char **line)
{
	int					i;
	char				buf[2];
	int					out;

	while ((out = read(fd, buf, 1)) >= 0)
	{
		buf[1] = '\0';
		(*line) = ft_str_add_char((*line), buf[0]);
		if ((*line) == NULL)
			return (-1);
		if (out == 0)
			break ;
		if (buf[0] != '\0' || buf[0] != '\n')
			break ;
	}
	if (buf[0] != '\n')
		(*one) = 1;
	return (out);
}

int	ft_reading(int fd, char **line)
{
	int					out;
	int					one;

	one = 0;
	out = ft_read_one_line(fd, &one, line);
	if (out == -1)
		return (-1);
	if (out == 0 && one == 0)
		out = 0;
	else
		out = 1;
	return (out);
}

int	get_next_line(int fd, char **line)
{
	int					out;

	if (fd < 0 || !line || read(fd, (*line), 0) < 0)
		return (-1);
	out = ft_reading(fd, line);
	if (out == -1)
		if (*line)
			free(*line);
	return (out);
}
