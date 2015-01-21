/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypr_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 11:27:37 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/22 16:46:00 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

static void		check_key_value(int key, t_data *data)
{
	if (key == KEY_SPACE)
	{
		data->pause = data->pause == 0 ? 1 : 0;
		return ;
	}
	if (data->pause)
		return ;
	/* if (key == KEY_RIGHT) */
	/* 	data->turn_right = 1; */
	/* else if (key == KEY_LEFT) */
	/* 	data->turn_left = 1; */
	/* else if (key == KEY_A) */
	/* 	data->strap_left = 1; */
	/* else if (key == KEY_D) */
	/* 	data->strap_right = 1; */
	/* else if (key == KEY_UP || key == KEY_W) */
	/* 	data->move_up = 1; */
	/* else if (key == KEY_DOWN || key == KEY_S) */
	/* 	data->move_down = 1; */
	/* else if (key == KEY_T) */
	/* 	data->display_textures = ABS(data->display_textures - 1); */
	/* else if (key == KEY_RET) */
	/* 	ft_action_key(data); */
}

#include <stdio.h>
int				ft_keypr_hook(int key, void *param)
{
	t_data	*data;

//	dprintf(0, "touche = %d\n", key);
	data = (t_data *)param;
	check_key_value(key, data);
	return (0);
}
