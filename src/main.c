/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 11:04:12 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 17:48:12 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fractol.h"

static int	ft_img_init(t_img **img, void *mlx_ptr, int width, int height)
{
	if (!(*img = (t_img *)malloc(sizeof(t_img))))
		return (ft_malloc_failed ());
	(*img)->width = width;
	(*img)->height = height;
	if (!((*img)->img_ptr = mlx_new_image(mlx_ptr, width, \
										height)))
		return (ft_malloc_failed());
	if (!((*img)->bmp = mlx_get_data_addr((*img)->img_ptr, &(*img)->bpp, \
										&(*img)->size_line, &(*img)->endian)))
		return (ft_malloc_failed ());
	return (1);
}

static int	ft_mlx_init(t_xdata *data, int ac)
{
	if (!(data->ptr = mlx_init()))
		return (ft_malloc_failed());
	if (!(data->win = mlx_new_window(data->ptr,
								(ac == 2 ? WINDOW_WIDTH : WINDOW_WIDTH * 2), \
								WINDOW_HEIGHT, "fract_ol")))
		ft_malloc_failed();
	return (1);
}

static int	sub_main(t_data *data, int ac, char **av)
{
	if (!ft_data_init(data, av))
		return (1);
	ft_read_colors(data);
	mlx_expose_hook(data->xdata->win, &ft_expose_hook, data->xdata);
	mlx_key_hook(data->xdata->win, &ft_key_hook, data);
	mlx_hook(data->xdata->win, KEYPRESS, KEYPRESSMASK, &ft_keypr_hook, data);
	mlx_hook(data->xdata->win, MOTIONNOTIFY, POINTERMOTIONMASK, \
			&ft_mouse_motion_hook, data);
	mlx_hook(data->xdata->win, BUTTONPRESS, BUTTONPRESSMASK, \
			&ft_btn_press_hook, data);
	mlx_loop_hook(data->xdata->ptr, &ft_loop, data->xdata);
	ft_render(data, data->xdata->img1, data->xdata->img1->draw_func);
	if (ac == 3)
		ft_render(data, data->xdata->img2, data->xdata->img2->draw_func);
	mlx_loop(data->xdata->ptr);
	ft_clean_prog(data->xdata);
	return (0);
}

int			main(int ac, char **av)
{
	t_data		data;
	t_xdata		xdata;

	data.xdata = &xdata;
	if (ac != 2 && ac != 3)
		return (ft_err_usage());
	if (!ft_mlx_init (&xdata, ac))
		return (1);
	if (ac == 2)
	{
		xdata.img_nbr = 1;
		xdata.img2 = NULL;
		if (!ft_img_init (&xdata.img1, xdata.ptr, WINDOW_WIDTH, WINDOW_HEIGHT))
			return (1);
	}
	else
	{
		xdata.img_nbr = 2;
		if (!ft_img_init (&xdata.img1, xdata.ptr, WINDOW_WIDTH, WINDOW_HEIGHT)
		|| !ft_img_init (&xdata.img2, xdata.ptr, WINDOW_WIDTH, WINDOW_HEIGHT))
			return (1);
	}
	return (!sub_main(&data, ac, av));
}
