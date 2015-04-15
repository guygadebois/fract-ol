/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:08:45 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 13:45:09 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_zoom_in(t_data* data)
{
	t_img*	img;

	if (data->xdata->img_nbr == 2 && data->mouse_x >= data->xdata->img1->width)
		img = data->xdata->img2;
	else
		img = data->xdata->img1;
	img->zoom *= 2.f;
	ft_render (data, img, img->draw_func);
}

void		ft_zoom_out(t_data* data)
{
	t_img*	img;

	if (data->xdata->img_nbr == 2 && data->mouse_x >= data->xdata->img1->width)
		img = data->xdata->img2;
	else
		img = data->xdata->img1;
	img->zoom *= 0.5f;
	if (img->zoom < 0.005f)
		img->zoom = 0.005f;
	ft_render (data, img, img->draw_func);
}
