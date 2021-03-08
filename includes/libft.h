/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:56:43 by nvu               #+#    #+#             */
/*   Updated: 2020/12/11 11:48:43 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>

int		ft_atoi(char *str);
size_t  ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, int start, int len);
int	    get_next_line(int fd, char **line);

#endif
