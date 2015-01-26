/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:47:01 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 14:54:29 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static int	ft_min(int a, int b)
{
	return (a < b ? a : b);
}

static int	set_draw_function(t_img *img, char *arg)
{
	if (ft_strcmp(arg, "julia") == 0)
	{
		img->draw_func = &ft_draw_julia;
		img->mod = JULIA_DEPTH;
	}
	else if (ft_strcmp(arg, "mandelbrot") == 0)
	{
		img->draw_func = &ft_draw_mandelbrot;
		img->mod = MANDELBROT_DEPTH;
	}
	else if (ft_strcmp(arg, "exp") == 0)
	{
		img->draw_func = &ft_draw_exp;
		img->mod = EXP_DEPTH;
	}
	else
	{
		ft_putstr_fd("Error: unknown fractal type: ", 2);
		ft_putendl_fd(arg, 2);
		return (0);
	}
	return (1);
}

int			ft_data_init(t_data *data, char **av)
{
	int		w;
	int		h;

	if (!set_draw_function(data->xdata->img1, av[1]))
		return (0);
	data->pause = 0;
	w = data->xdata->img1->width;
	h = data->xdata->img1->height;
	data->xdata->img1->zoom = 1 / (4.f / (float)ft_min(w, h));
	data->xdata->img1->default_zoom = data->xdata->img1->zoom;
	data->xdata->img1->c_x = 0.455f;
	data->xdata->img1->c_y = 0.115f;
	data->xdata->img1->z0_x = 0;
	data->xdata->img1->z0_y = 0;
	data->xdata->img1->color1 = 0x0;
	data->xdata->img1->color2 = 0xFF0000;
	data->xdata->img1->color3 = 0x00FF00;
	data->xdata->img1->color4 = 0x0;
	if (data->xdata->img_nbr == 2)
	{
		if (!set_draw_function(data->xdata->img2, av[2]))
			return (0);
		w = data->xdata->img2->width;
		h = data->xdata->img2->height;
		data->xdata->img2->zoom = 1 / (4.f / (float)ft_min(w, h));
		data->xdata->img2->default_zoom = data->xdata->img2->zoom;
		data->xdata->img2->c_x = -0.28f;
		data->xdata->img2->c_y = 0.77;
		data->xdata->img2->z0_x = 0;
		data->xdata->img2->z0_y = 0;
		data->xdata->img2->color1 = 0x0;
		data->xdata->img2->color2 = 0xFF0000;
		data->xdata->img2->color3 = 0x00FF00;
		data->xdata->img2->color4 = 0x0;
	}
	return (1);
}
