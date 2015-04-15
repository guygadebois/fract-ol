/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 21:02:12 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 17:37:25 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include "fractol.h"

#define ZOOM img->default_zoom

int			ft_key_hook(unsigned int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == 65307)
	{
		ft_clean_prog(data->xdata);
		exit(EXIT_SUCCESS);
	}
	if (data->pause)
		return (0);
	if (key == 65451)
		ft_zoom_in(data);
	else if (key == 65453)
		ft_zoom_out(data);
	else if (key == 109)
		ft_decr_modulo(data);
	else if (key == 110)
		ft_incr_modulo(data);
	return (0);
}

int			ft_expose_hook(void *param)
{
	(void)param;
	return (0);
}

static void	update_values(t_img *img, int x, int y)
{
	img->c_x = (float)(x - img->width / 2) / img->default_zoom;
	img->c_y = (float)(y - img->height / 2) / img->default_zoom;
	img->z0_x = (float)(x - img->width / 2) / img->default_zoom;
	img->z0_y = (float)(y - img->height / 2) / img->default_zoom;
}

int			ft_mouse_motion_hook(int x, int y, void *param)
{
	t_data	*data;
	t_img	*img;

	data = (t_data *)param;
	data->mouse_x = x;
	data->mouse_y = y;
	if (data->pause)
		return (0);
	if (data->xdata->img_nbr == 2 && x >= data->xdata->img1->width)
	{
		img = data->xdata->img2;
		img->c_x = (float)(x - img->width - img->width / 2) / ZOOM;
		img->c_y = (float)(y - img->height / 2) / img->default_zoom;
		img->z0_x = (float)(x - img->width - img->width / 2) / ZOOM;
		img->z0_y = (float)(y - img->height / 2) / img->default_zoom;
	}
	else
	{
		img = data->xdata->img1;
		update_values(img, x, y);
	}
	ft_render (data, img, img->draw_func);
	return (0);
}

int			ft_btn_press_hook(int button, int x, int y, void *param)
{
	static int	zoom_buf = 0;
	t_data		*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (data->pause)
		return (0);
	if (button == MOUSE_BTN_SCROLL_UP)
	{
		if (++zoom_buf >= 7)
		{
			zoom_buf = 0;
			ft_zoom_in(data);
		}
	}
	else if (button == MOUSE_BTN_SCROLL_DOWN)
	{
		if (--zoom_buf <= -7)
		{
			zoom_buf = 0;
			ft_zoom_out(data);
		}
	}
	return (0);
}
