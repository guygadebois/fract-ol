/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/19 14:18:49 by glourdel          #+#    #+#             */
/*   Updated: 2013/11/25 21:35:00 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (s1 && s2)
	{
		while (s2[i])
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
		return (s1);
	}
	else
		return (NULL);
}
