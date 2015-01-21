/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 16:34:35 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/21 17:42:10 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fractol.h"

static int	julia_calc_color(t_data *data, t_img *img, int x, int y)
{
	int		color;

	color = (int)((float)x * 0xFFFFFF / 2  / (float)img->width + (float)y * 0xFFFFFF / 2 / (float)img->height);
	color = x < img->width / 2 ? 0xFF0000 : 0x00FF00;
	color = y < img->height / 2 ? color : 0x0000FF;
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
