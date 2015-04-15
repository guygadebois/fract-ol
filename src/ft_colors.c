/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 14:48:50 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 17:54:28 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_add_colors(int c1, int c2)
{
	int		r;
	int		g;
	int		b;

	r = (c1 >> 16 & 0xFF) + (c2 >> 16 & 0xFF);
	g = (c1 >> 8 & 0xFF) + (c2 >> 8 & 0xFF);
	b = (c1 & 0xFF) + (c2 & 0xFF);
	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;
	return (0x0 | (r << 16) | (g << 8) | b);
}

int			ft_mult_color(int c, float mult)
{
	int		r;
	int		g;
	int		b;

	r = (int)((float)(c >> 16 & 0xFF) * mult);
	g = (int)((float)(c >> 8 & 0xFF) * mult);
	b = (int)((float)(c & 0xFF) * mult);
	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;
	return (0x0 | (r << 16) | (g << 8) | b);
}

int			ft_blend_colors(int c1, int c2)
{
	return (ft_add_colors(ft_mult_color(c1, 0.5f), ft_mult_color(c2, 0.5f)));
}

int			ft_mult_colors(int c1, int c2)
{
	int		r;
	int		g;
	int		b;

	r = (c1 >> 16 & 0xFF) * (c2 >> 16 & 0xFF);
	g = (c1 >> 8 & 0xFF) * (c2 >> 8 & 0xFF);
	b = (c1 & 0xFF) * (c2 & 0xFF);
	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;
	return (0x0 | (r << 16) | (g << 8) | b);
}
