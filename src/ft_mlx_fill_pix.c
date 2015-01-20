/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_fill_pix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:07:41 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/20 15:48:33 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

static void	fill_pix(t_xdata *xdata, char *pixel_ptr, int color)
{
	unsigned int	*ptr;

	ptr = (unsigned int *)pixel_ptr;
	*ptr = mlx_get_color_value(xdata->ptr, color);
}

void		ft_mlx_fill_pix(t_xdata *xdata, int x, int y, int color)
{
	if (x >= 0 && x < xdata->img.width && y >= 0 && y < xdata->img.height)
		fill_pix(xdata, ft_mlx_gotopix(&xdata->img, x, y), color);
}
