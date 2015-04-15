/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 22:11:58 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 17:55:43 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

int			ft_loop(void *param)
{
	t_xdata	*xdata;

	xdata = (t_xdata *)param;
	mlx_put_image_to_window(xdata->ptr, xdata->win, \
							xdata->img1->img_ptr, 0, 0);
	if (xdata->img_nbr == 2)
	{
		mlx_put_image_to_window(xdata->ptr, xdata->win, \
								xdata->img2->img_ptr, xdata->img1->width, 0);
	}
	return (0);
}
