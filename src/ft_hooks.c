/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 21:02:12 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/20 16:17:02 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fractol.h"

int		ft_key_hook(unsigned int key, void *data)
{
	t_xdata	*xdata;

	xdata = (t_xdata *)data;
	if (key == 65307)
	{
		mlx_destroy_window(xdata->ptr, xdata->win);
		xdata->win = NULL;
		ft_clean_prog();
		exit(EXIT_SUCCESS);
	}
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
	t_xdata	*xdata;

	xdata = (t_xdata *)param;
	mlx_put_image_to_window(xdata->ptr, xdata->win,		\
							xdata->img.img_ptr, 0, 0);
	return (0);
}
