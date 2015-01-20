/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:16:36 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/20 16:01:22 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "fractol_types.h"

int			ft_err_usage(void);
int			ft_malloc_failed(void);
int			ft_error(char const* msg);

char		*ft_mlx_gotopix(t_img *img, int x, int y);
void		ft_mlx_fill_pix(t_xdata *xdata, int x, int y, int color);
int			ft_mlx_getcolor(unsigned int r, unsigned int g, unsigned int b);

int			ft_keypr_hook(int key, void *param);
int			ft_key_hook(unsigned int key, void *data);
int			ft_expose_hook(void *param);
int			ft_loop(void *param);

void		ft_clean_prog(void);

#endif	/* FRACTOL_H */
