/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_prog.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:45:54 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/22 12:40:46 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fractol.h"

void		ft_clean_prog(t_xdata *xdata)
{
	mlx_destroy_image(xdata->ptr, xdata->img1->img_ptr);
	free (xdata->img1);
	if (xdata->img2)
	{
		mlx_destroy_image(xdata->ptr, xdata->img2->img_ptr);
		free (xdata->img2);
	}
	mlx_destroy_window(xdata->ptr, xdata->win);
	free (xdata->ptr);
}
