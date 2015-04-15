/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 12:26:28 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 13:37:42 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include "fractol.h"
#include <stdio.h> // TODO
static int	mandelbrot_calc_color(t_data *data, t_img *img, int x, int y)
{
	int		color;
	float	z_x;
	float	z_y;
	int		depth;
	float	old_x;

	depth = 0;
//	dprintf(0, "DBG 0\n");
	img->c_x = (float)(x - img->width / 2) / img->zoom;
	img->c_y = (float)(y - img->height / 2) / img->zoom;
//	dprintf(0, "DBG 1\n");
	z_x = img->z0_x;
	z_y = img->z0_y;
	while (z_x * z_x + z_y * z_y < 4.f && ++depth < MANDELBROT_DEPTH)
	{
//		dprintf(0, "DBG 2\n");
		old_x = z_x;
		z_x = z_x * z_x - z_y * z_y + img->c_x;
		z_y = 2.f * old_x * z_y + img->c_y;
	}
	if (depth == 0)
		color = img->color4;
	else if (depth == MANDELBROT_DEPTH)
		color = img->color1;
	else if (depth > 0 && depth < 32)
		color = ft_add_colors (ft_mult_color(img->color3, \
									(float)depth / (float)32), img->color4);
	else
		color = ft_mult_color (img->color2, (float)depth / (float)MANDELBROT_DEPTH);
	return (mlx_get_color_value(data->xdata->ptr, color));
}

void		*ft_draw_mandelbrot(void *thread_data)
{
	t_rect	*rect;
	t_img	*img;
	t_data	*data;
	int		i;
	int		j;

	rect = ((t_thread_data *)thread_data)->rect;
	img = ((t_thread_data *)thread_data)->img;
	data = ((t_thread_data *)thread_data)->data;
	i = 0;
	while (i < rect->w)
	{
		j = 0;
		while (j < rect->h)
		{
			ft_mlx_fill_pix(img, rect->x + i, rect->y + j, \
							mandelbrot_calc_color(data, img, rect->x + i, \
										rect->y + j));
			++j;
		}
		++i;
	}
	free (thread_data);
	return (NULL);
}
