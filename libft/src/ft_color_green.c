/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_green.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 10:35:35 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/11 10:35:57 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_color_green(char *str)
{
	return (ft_strjoin(ft_strjoin("\033[32;1m", str), "\033[0m"));
}