/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:23:35 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/20 16:47:58 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_types_H
# define FRACTOL_types_H

# define WINDOW_WIDTH	1600
# define WINDOW_HEIGHT	800

# define KEYPRESSMASK	1L<<0
# define KEYPRESS		2

# define FT_BLACK		0x000000

typedef struct		s_img
{
	void		*img_ptr;
	int			width;
	int			height;
	int			bpp;
	int			endian;
	int			size_line;
	char		*bmp;
}					t_img;

typedef struct		s_xdata
{
	void		*ptr;
	void		*win;
	t_img		img;
}					t_xdata;

typedef struct		s_data
{
	//TODO
}					t_data;

#endif	/* FRACTOL_types_H */
