/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <nvu@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:24:53 by nvu               #+#    #+#             */
/*   Updated: 2021/03/10 09:24:55 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main(int ac, char **av)
{
    t_params    *params;
    int         out;

    params = ft_parsing(ac, av);
    if (params == NULL)
        return (-1);
    out = ft_display(params);
    if (out == -1)
        return (-1);
    return (0);
}