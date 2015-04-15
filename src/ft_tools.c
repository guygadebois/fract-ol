/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:47:01 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 17:40:50 by glourdel         ###   ########.fr       */
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
		img->c_x = 0.22f;
		img->c_y = 1.63333f;
	}
	else
	{
		ft_putstr_fd("Error: unknown fractal type: ", 2);
		ft_putendl_fd(arg, 2);
		return (0);
	}
	return (1);
}

static void	init_img1(t_img *img1, int w, int h)
{
	img1->zoom = 1 / (4.f / (float)ft_min(w, h));
	img1->default_zoom = img1->zoom;
	img1->c_x = 0.455f;
	img1->c_y = 0.115f;
	img1->z0_x = 0;
	img1->z0_y = 0;
	img1->color1 = 0x0;
	img1->color2 = 0x8855CC;
	img1->color3 = 0x00FF00;
	img1->color4 = 0x0;
}

int			ft_data_init(t_data *data, char **av)
{
	data->pause = 0;
	init_img1(data->xdata->img1, data->xdata->img1->width, \
			data->xdata->img1->height);
	if (!set_draw_function(data->xdata->img1, av[1]))
		return (0);
	if (data->xdata->img_nbr == 2)
	{
		data->xdata->img2->zoom = 1 / (4.f
	/ (float)ft_min(data->xdata->img2->width, data->xdata->img2->height));
		data->xdata->img2->default_zoom = data->xdata->img2->zoom;
		data->xdata->img2->c_x = -0.28f;
		data->xdata->img2->c_y = 0.77;
		data->xdata->img2->z0_x = 0;
		data->xdata->img2->z0_y = 0;
		data->xdata->img2->color1 = 0x0;
		data->xdata->img2->color2 = 0x8855CC;
		data->xdata->img2->color3 = 0x00FF00;
		data->xdata->img2->color4 = 0x0;
		if (!set_draw_function(data->xdata->img2, av[2]))
			return (0);
	}
	return (1);
}
