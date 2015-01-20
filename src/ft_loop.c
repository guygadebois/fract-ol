
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 22:11:58 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/20 16:18:59 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

static void	reset_background(t_xdata *xdata)
{
	int		i;
	int		j;

	i = 0;
	while (i < xdata->img.height)
	{
		j = 0;
		while (j < xdata->img.width)
		{
			ft_mlx_fill_pix(xdata, j, i, FT_BLACK);
			j++;
		}
		i++;
	}
}

int			ft_loop(void *param)
{
	t_xdata	*xdata;

	xdata = (t_xdata *)param;
	reset_background(xdata);
	mlx_put_image_to_window(xdata->ptr, xdata->win,		\
							xdata->img.img_ptr, 0, 0);
	return (0);
}
