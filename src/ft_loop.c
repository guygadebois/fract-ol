
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 22:11:58 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/20 18:03:17 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

static void	reset_background(t_img *img, void *mlx_ptr, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			ft_mlx_fill_pix(img, j, i, \
							mlx_get_color_value(mlx_ptr, color));
			j++;
		}
		i++;
	}
}

int			ft_loop(void *param)
{
	t_xdata	*xdata;

	xdata = (t_xdata *)param;
	reset_background(xdata->img1, xdata->ptr, FT_BLACK);
	mlx_put_image_to_window(xdata->ptr, xdata->win,		\
							xdata->img1->img_ptr, 0, 0);
	if (xdata->img_nbr == 2)
	{
		reset_background(xdata->img2, xdata->ptr, FT_WHITE);
		mlx_put_image_to_window(xdata->ptr, xdata->win,	\
								xdata->img2->img_ptr, xdata->img1->width, 0);
	}
	return (0);
}
