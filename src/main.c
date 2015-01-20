/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 11:04:12 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/20 17:16:42 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

static int	ft_mlx_init(t_xdata *data)
{
	data->img.width = WINDOW_WIDTH;
	data->img.height = WINDOW_HEIGHT;
	if (!(data->ptr = mlx_init()))
		return (ft_malloc_failed());
	if (!(data->win = mlx_new_window(data->ptr, data->img.width, \
									 data->img.height, "fract_ol")))
		ft_malloc_failed();
	if (!(data->img.img_ptr = mlx_new_image(data->ptr, data->img.width, \
											data->img.height)))
		ft_malloc_failed();
	if (!(data->img.bmp = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, \
											&data->img.size_line, &data->img.endian)))
		return (ft_malloc_failed());
	return (1);
}


int			main(int ac, char **av)
{
	t_xdata		xdata;

	if (ac != 2)
		return (ft_err_usage());
	(void)av; //TODO
	ft_mlx_init (&xdata);
	mlx_expose_hook(xdata.win, &ft_expose_hook, &xdata);
	mlx_key_hook(xdata.win, &ft_key_hook, &xdata);
	mlx_hook(xdata.win, KEYPRESS, KEYPRESSMASK, &ft_keypr_hook, &xdata);
	mlx_hook(xdata.win, MOTIONNOTIFY, POINTERMOTIONMASK, &ft_mouse_motion_hook, &xdata);
	mlx_hook(xdata.win, BUTTONPRESS, BUTTONPRESSMASK, &ft_btn_press_hook, &xdata);
	mlx_loop_hook(xdata.ptr, &ft_loop, &xdata);
	mlx_loop(xdata.ptr);
	ft_clean_prog();
	return (0);
}
