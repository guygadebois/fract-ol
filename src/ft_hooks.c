/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 21:02:12 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 13:44:30 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include "fractol.h"
#include <stdio.h> // TODO

int		ft_key_hook(unsigned int key, void *param)
{
	t_data	*data;

//	dprintf(0, "key = %d\n", key);
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
	/* if (key == KEY_RIGHT) */
	/* 	((t_data *)data)->turn_right = 0; */
	/* else if (key == KEY_LEFT) */
	/* 	((t_data *)data)->turn_left = 0; */
	/* else if (key == KEY_A) */
	/* 	((t_data *)data)->strap_left = 0; */
	/* else if (key == KEY_D) */
	/* 	((t_data *)data)->strap_right = 0; */
	/* else if (key == KEY_UP || key == KEY_W) */
	/* 	((t_data *)data)->move_up = 0; */
	/* else if (key == KEY_DOWN || key == KEY_S) */
	/* 	((t_data *)data)->move_down = 0; */
	return (0);
}

int		ft_expose_hook(void *param)
{
	(void)param;
	return (0);
}

int		ft_mouse_motion_hook(int x, int y, void *param)
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
		img->c_x = (float)(x - img->width - img->width / 2) / img->default_zoom;
		img->c_y = (float)(y - img->height / 2) / img->default_zoom;
		img->z0_x = (float)(x - img->width - img->width / 2) / img->default_zoom;
		img->z0_y = (float)(y - img->height / 2) / img->default_zoom;
	}
	else
	{
		img = data->xdata->img1;
		img->c_x = (float)(x - img->width / 2) / img->default_zoom;
		img->c_y = (float)(y - img->height / 2) / img->default_zoom;
		img->z0_x = (float)(x - img->width / 2) / img->default_zoom;
		img->z0_y = (float)(y - img->height / 2) / img->default_zoom;
	}
//	dprintf(0, "cx = %f, cy = %f\n", img->c_x, img->c_y);
	ft_render (data, img, img->draw_func);
	return (0);
}

int		ft_btn_press_hook (int button, int x, int y, void *param)
{
	t_data*		data;
	static int	zoom_buf = 0;

	(void)x;
	(void)y;
	data = (t_data *)param;
//	dprintf (0, "button: %d, x: %d, y: %d\n", button, x, y); // TODO
	if (data->pause)
		return (0);
	if (button == MOUSE_BTN_SCROLL_UP)
	{
		zoom_buf += 1;
		if (zoom_buf >= 7)
		{
			zoom_buf = 0;
			ft_zoom_in(data);
		}
	}
	else if (button == MOUSE_BTN_SCROLL_DOWN)
	{
		zoom_buf -= 1;
		if (zoom_buf <= -7)
		{
			zoom_buf = 0;
			ft_zoom_out(data);
		}
	}
	return (0);
}
