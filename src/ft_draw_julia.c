/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 16:34:35 by glourdel          #+#    #+#             */
/*   Updated: 2015/04/15 15:40:21 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include "fractol.h"

static int	julia_calc_color(t_data *data, t_img *img, int x, int y)
{
	int		color;
	float	z_x;
	float	z_y;
	int		depth;
	float	old_x;

	depth = 0;
	z_x = (float)(x - img->width / 2) / img->zoom;
	z_y = (float)(y - img->height / 2) / img->zoom;
	while (z_x * z_x + z_y * z_y < 4.f && ++depth < JULIA_DEPTH)
	{
		old_x = z_x;
		z_x = z_x * z_x - z_y * z_y + img->c_x;
		z_y = 2.f * old_x * z_y + img->c_y;
	}
	if (depth == 0)
		color = img->color4;
	else if (depth == JULIA_DEPTH)
		color = img->color1;
	else if (depth > 0 && depth < 32)
		color = ft_add_colors (ft_mult_color(img->color3, \
									(float)depth / (float)32), img->color4);
	else
		color = img->color2;
	return (mlx_get_color_value(data->xdata->ptr, color));
}

void		*ft_draw_julia(void *thread_data)
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
							julia_calc_color(data, img, rect->x + i, \
										rect->y + j));
			++j;
		}
		++i;
	}
	free (thread_data);
	return (NULL);
}
