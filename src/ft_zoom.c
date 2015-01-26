/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:08:45 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 14:36:45 by glourdel         ###   ########.fr       */
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

void		ft_decr_modulo(t_data* data)
{
	t_img*	img;

	if (data->xdata->img_nbr == 2 && data->mouse_x >= data->xdata->img1->width)
		img = data->xdata->img2;
	else
		img = data->xdata->img1;
	img->mod -= 1;
	if (img->mod < 2)
		img->mod = 2;
	ft_render (data, img, img->draw_func);
}

void		ft_incr_modulo(t_data* data)
{
	t_img*	img;

	if (data->xdata->img_nbr == 2 && data->mouse_x >= data->xdata->img1->width)
		img = data->xdata->img2;
	else
		img = data->xdata->img1;
	img->mod += 1;
	if (img->draw_func == &ft_draw_julia && img->mod > JULIA_DEPTH)
		img->mod = JULIA_DEPTH;
	if (img->draw_func == &ft_draw_mandelbrot && img->mod > MANDELBROT_DEPTH)
		img->mod = MANDELBROT_DEPTH;
	ft_render (data, img, img->draw_func);
}
