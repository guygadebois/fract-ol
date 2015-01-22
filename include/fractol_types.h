/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:23:35 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/22 17:14:29 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_types_H
# define FRACTOL_types_H

# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	800

# define KEYPRESSMASK	1L<<0
# define KEYPRESS		2
# define POINTERMOTIONMASK	(1L<<6)
# define MOTIONNOTIFY		6
# define BUTTONPRESSMASK	(1L<<2)
# define BUTTONPRESS		4

# define KEY_SPACE			32

# define MOUSE_BTN_SCROLL_DOWN	4
# define MOUSE_BTN_SCROLL_UP	5

# define FT_BLACK				0x000000
# define FT_WHITE				0xFFFFFF

# define JULIA_DEPTH			100


typedef struct		s_img
{
	void		*img_ptr;
	int			width;
	int			height;
	int			bpp;
	int			endian;
	int			size_line;
	char		*bmp;
	int			color1;
	int			color2;
	int			color3;
	int			color4;
	float		zoom;
	float		default_zoom;
	float		c_x;
	float		c_y;
	float		z0_x;
	float		z0_y;
}					t_img;

typedef struct		s_xdata
{
	void		*ptr;
	void		*win;
	t_img		*img1;
	t_img		*img2;
	int			img_nbr;
}					t_xdata;

typedef struct		s_data
{
	t_xdata		*xdata;
	int			pause;
	int			mouse_x;
	int			mouse_y;
}					t_data;

typedef struct		s_rect
{
	int			x;
	int			y;
	int			h;
	int			w;
}					t_rect;

typedef struct		s_thread_data
{
	t_data		*data;
	t_img		*img;
	t_rect		*rect;
}					t_thread_data;

#endif	/* FRACTOL_types_H */
