/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 16:58:56 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/21 17:01:23 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_render(t_data *data, t_img *img, void *(*draw_func)(void *))
{
	pthread_t	thread[4];

	thread[0] = ft_launch_thread1(data, img, draw_func);
	thread[1] = ft_launch_thread2(data, img, draw_func);
	thread[2] = ft_launch_thread3(data, img, draw_func);
	thread[3] = ft_launch_thread4(data, img, draw_func);
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
	pthread_join(thread[3], NULL);
}
