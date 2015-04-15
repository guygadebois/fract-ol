/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 22:00:58 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 18:02:28 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

static pthread_t	launch_thread(t_data *data, t_img *img, t_rect *rect, \
								void *(*draw_func)(void *))
{
	pthread_t		thread;
	t_thread_data	*thread_data;

	if (!(thread_data = (t_thread_data *)malloc(sizeof(t_thread_data))))
	{
		ft_malloc_failed();
		return (0);
	}
	thread_data->data = data;
	thread_data->img = img;
	thread_data->rect = rect;
	if (pthread_create(&thread, NULL, draw_func, thread_data))
	{
		return (0);
	}
	return (thread);
}

pthread_t			ft_launch_thread1(t_data *data, t_img *img, \
									void *(*draw_func)(void *))
{
	t_rect		*rect;

	if (!(rect = (t_rect *)malloc(sizeof(t_rect))))
	{
		ft_malloc_failed();
		return (0);
	}
	rect->x = 0;
	rect->y = 0;
	rect->w = img->width / 2;
	rect->h = img->height / 2;
	return (launch_thread(data, img, rect, draw_func));
}

pthread_t			ft_launch_thread2(t_data *data, t_img *img, \
									void *(*draw_func)(void *))
{
	t_rect		*rect;

	if (!(rect = (t_rect *)malloc(sizeof(t_rect))))
	{
		ft_malloc_failed();
		return (0);
	}
	rect->x = img->width / 2;
	rect->y = 0;
	rect->w = img->width / 2;
	rect->h = img->height / 2;
	return (launch_thread(data, img, rect, draw_func));
}

pthread_t			ft_launch_thread3(t_data *data, t_img *img, \
									void *(*draw_func)(void *))
{
	t_rect		*rect;

	if (!(rect = (t_rect *)malloc(sizeof(t_rect))))
	{
		ft_malloc_failed();
		return (0);
	}
	rect->x = img->width / 2;
	rect->y = img->height / 2;
	rect->w = img->width / 2;
	rect->h = img->height / 2;
	return (launch_thread(data, img, rect, draw_func));
}

pthread_t			ft_launch_thread4(t_data *data, t_img *img, \
									void *(*draw_func)(void *))
{
	t_rect		*rect;

	if (!(rect = (t_rect *)malloc(sizeof(t_rect))))
	{
		ft_malloc_failed();
		return (0);
	}
	rect->x = 0;
	rect->y = img->height / 2;
	rect->w = img->width / 2;
	rect->h = img->height / 2;
	return (launch_thread(data, img, rect, draw_func));
}
