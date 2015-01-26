/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:47:01 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 12:01:09 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_min(int a, int b)
{
	return (a < b ? a : b);
}

void		ft_data_init(t_data *data)
{
	int		w;
	int		h;

	data->pause = 0;
	w = data->xdata->img1->width;
	h = data->xdata->img1->height;
	data->xdata->img1->zoom = 1 / (4.f / (float)ft_min(w, h));
	data->xdata->img1->default_zoom = data->xdata->img1->zoom;
	data->xdata->img1->c_x = 0.455f;
	data->xdata->img1->c_y = 0.115f;
	data->xdata->img1->z0_x = 0;
	data->xdata->img1->z0_y = 0;
	data->xdata->img1->color1 = 0x0;
	data->xdata->img1->color2 = 0xFF0000;
	data->xdata->img1->color3 = 0x00FF00;
	data->xdata->img1->color4 = 0x0;
	if (data->xdata->img_nbr == 2)
	{
		w = data->xdata->img2->width;
		h = data->xdata->img2->height;
		data->xdata->img2->zoom = 1 / (4.f / (float)ft_min(w, h));
		data->xdata->img2->default_zoom = data->xdata->img2->zoom;
		data->xdata->img2->c_x = -0.28f;
		data->xdata->img2->c_y = 0.77;
		data->xdata->img2->z0_x = 0;
		data->xdata->img2->z0_y = 0;
		data->xdata->img2->color1 = 0x0;
		data->xdata->img2->color2 = 0xFF0000;
		data->xdata->img2->color3 = 0x00FF00;
		data->xdata->img2->color4 = 0x0;
	}
}
