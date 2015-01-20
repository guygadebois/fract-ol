/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypr_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 11:27:37 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/20 15:32:18 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

/* static void		check_key_value(int key, t_data *data) */
/* { */
/* 	(void)key; */
/* 	(void)data; */
/* 	//TODO */
/* 	/\* if (key == KEY_RIGHT) *\/ */
/* 	/\* 	data->turn_right = 1; *\/ */
/* 	/\* else if (key == KEY_LEFT) *\/ */
/* 	/\* 	data->turn_left = 1; *\/ */
/* 	/\* else if (key == KEY_A) *\/ */
/* 	/\* 	data->strap_left = 1; *\/ */
/* 	/\* else if (key == KEY_D) *\/ */
/* 	/\* 	data->strap_right = 1; *\/ */
/* 	/\* else if (key == KEY_UP || key == KEY_W) *\/ */
/* 	/\* 	data->move_up = 1; *\/ */
/* 	/\* else if (key == KEY_DOWN || key == KEY_S) *\/ */
/* 	/\* 	data->move_down = 1; *\/ */
/* 	/\* else if (key == KEY_T) *\/ */
/* 	/\* 	data->display_textures = ABS(data->display_textures - 1); *\/ */
/* 	/\* else if (key == KEY_SPACE) *\/ */
/* 	/\* 	ft_open_fire(data); *\/ */
/* 	/\* else if (key == KEY_RET) *\/ */
/* 	/\* 	ft_action_key(data); *\/ */
/* } */

int				ft_keypr_hook(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)data;
	(void)key;
	//TODO
	return (0);
}
