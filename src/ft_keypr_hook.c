/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypr_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 11:27:37 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 17:55:07 by glourdel         ###   ########.fr       */
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
}

int				ft_keypr_hook(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	check_key_value(key, data);
	return (0);
}
