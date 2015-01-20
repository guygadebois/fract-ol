/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:19:06 by glourdel          #+#    #+#             */
/*   Updated: 2015/04/15 15:20:33 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define RED_START "\033[31m"
#define RED_END   "\033[0m"


int		ft_error(char const *msg)
{
	ft_putstr_fd(RED_START, 2);
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(RED_END, 2);
	return (1);
}

int		ft_err_usage(void)
{
	return (ft_error("usage : fractol FRACTAL_TYPE"));
}

int		ft_malloc_failed(void)
{
	return (ft_error("malloc() failed"));
}
