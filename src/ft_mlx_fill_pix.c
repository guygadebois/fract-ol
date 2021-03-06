/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_fill_pix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:07:41 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/20 18:03:38 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

static void	fill_pix(char *pixel_ptr, int color)
{
	unsigned int	*ptr;

	ptr = (unsigned int *)pixel_ptr;
	*ptr = color;
}

void		ft_mlx_fill_pix(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
		fill_pix(ft_mlx_gotopix(img, x, y), color);
}
