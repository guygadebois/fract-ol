/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:53:05 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 16:51:46 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include "fractol.h"

#define ABS(x) (x < 0 ? (x * -1) : (x))

static void	update_values(float *z_x, float *z_y, float e)
{
	float	old_x;

	old_x = (*z_x);
	if (e < 0.000000001f)
	{
		e *= -1.f;
		*z_x = powf(e, *z_x) * cosf(*z_y);
		*z_y = powf(e, old_x) * sinf(*z_y);
	}
	else
	{
		*z_x = powf(e, *z_x) * sinf(*z_y);
		*z_y = powf(e, old_x) * cosf(*z_y);
	}
}

static int	exp_calc_color(t_data *data, t_img *img, int x, int y)
{
	int		color;
	float	z_x;
	float	z_y;
	int		depth;

	depth = 0;
	z_x = (float)(x - img->width / 2) / img->zoom;
	z_y = (float)(y - img->height / 2) / img->zoom;
	while (z_x * z_x + z_y * z_y > 0.00001f && ++depth < EXP_DEPTH)
		update_values (&z_x, &z_y, img->c_x * 10);
	depth %= img->mod;
	if (depth == 0)
		color = img->color4;
	else if (depth == EXP_DEPTH)
		color = img->color1;
	else if (depth > 0 && depth < 6)
		color = ft_add_colors (ft_mult_color(img->color3, \
(float)depth / (float)(img->mod < 6 ? img->mod : 6)), img->color4);
	else
		color = ft_mult_color (img->color2, (float)depth / (float)EXP_DEPTH);
	return (mlx_get_color_value(data->xdata->ptr, color));
}

void		*ft_draw_exp(void *thread_data)
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
							exp_calc_color(data, img, rect->x + i, \
										rect->y + j));
			++j;
		}
		++i;
	}
	free (thread_data);
	return (NULL);
}
