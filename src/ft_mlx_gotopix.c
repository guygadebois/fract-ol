/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_gotopix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:29:21 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/20 15:37:40 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_mlx_gotopix(t_img *img, int x, int y)
{
	return (img->bmp + img->bpp / 8 * x + y * img->size_line);
}
