/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_getcolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:32:26 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/20 14:44:45 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_mlx_getcolor(unsigned int r, unsigned int g, unsigned int b)
{
	char	*result;

	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;
	if ((result = ft_strnew(4)))
	{
		result[0] = (unsigned char)b;
		result[1] = (unsigned char)g;
		result[2] = (unsigned char)r;
		result[3] = (unsigned char)0;
		return (*(int *)result);
	}
	else
		return (0);
}
