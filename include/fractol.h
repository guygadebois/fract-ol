/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:16:36 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/21 17:31:57 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include "fractol_types.h"

int			ft_err_usage(void);
int			ft_malloc_failed(void);
int			ft_error(char const* msg);

char		*ft_mlx_gotopix(t_img *img, int x, int y);
void		ft_mlx_fill_pix(t_img *img, int x, int y, int color);
int			ft_mlx_getcolor(unsigned int r, unsigned int g, unsigned int b);

int			ft_keypr_hook(int key, void *param);
int			ft_key_hook(unsigned int key, void *data);
int			ft_expose_hook(void *param);
int			ft_mouse_motion_hook(int x, int y, void *param);
int			ft_btn_press_hook (int button, int x, int y, void *param);
int			ft_loop(void *param);

void		ft_clean_prog(t_xdata *xdata);

pthread_t	ft_launch_thread1(t_data *data, t_img *img, \
							  void *(*draw_func)(void *));
pthread_t	ft_launch_thread2(t_data *data, t_img *img, \
							  void *(*draw_func)(void *));
pthread_t	ft_launch_thread3(t_data *data, t_img *img, \
							  void *(*draw_func)(void *));
pthread_t	ft_launch_thread4(t_data *data, t_img *img, \
							  void *(*draw_func)(void *));
void		ft_render(t_data *data, t_img *img, void *(*draw_func)(void *));

void		*ft_draw_julia(void *thread_data);

#endif	/* FRACTOL_H */
