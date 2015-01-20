/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:22:29 by glourdel          #+#    #+#             */
/*   Updated: 2013/12/18 15:28:44 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_last_char(const char *str)
{
	if (str)
	{
		if (*str == 0)
			return (0);
		while (*(str + 1))
			str++;
	}
	return ((char *)str);
}