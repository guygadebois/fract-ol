/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:15:36 by glourdel          #+#    #+#             */
/*   Updated: 2015/01/26 16:31:05 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "fractol.h"
#include "get_next_line.h"

static void	treat_line(t_data *data, char* line)
{
	t_img	*img;
	int		*color;

	if (ft_strncmp(line, "image1->", 8) == 0)
		img = data->xdata->img1;
	else if (ft_strncmp(line, "image2->", 8) == 0)
		img = data->xdata->img2;
	else
		return ;
	if (img == NULL)
		return ;
	if (ft_strncmp(line + 8, "color1: ", 8) == 0)
		color = &img->color1;
	else if (ft_strncmp(line + 8, "color2: ", 8) == 0)
		color = &img->color2;
	else if (ft_strncmp(line + 8, "color3: ", 8) == 0)
		color = &img->color3;
	else if (ft_strncmp(line + 8, "color4: ", 8) == 0)
		color = &img->color4;
	else
		return ;
	*color = strtol(line + 16, NULL, 16);
}

void		ft_read_colors(t_data *data)
{
	char	*line;
	int		fd;
	int		ret = -10;

	line = NULL;
	if ((fd = open("fractol.colors", O_RDONLY)) == -1)
		return ;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putendl (line);
		treat_line(data, line);
		free(line);
		line = NULL;
	}
}
