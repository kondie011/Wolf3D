/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:13:33 by knedzing          #+#    #+#             */
/*   Updated: 2018/08/15 07:39:44 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

void	errors(t_mlx *mlx)
{
	int		fd;
	char	*line;
	char	**split;
	int		x;
	int		y;

	if ((fd = open(mlx->f_n, O_RDONLY)) < 0)
		exit(0);
	y = 0;
	while (get_next_line(fd, &line) == 1 && ++y > 0 && (x = -1))
	{
		split = ft_strsplit(line, ' ');
		free(line);
		while (split[++x])
			if (y == 1)
				mlx->width = x + 1;
		if (fi(split) && x != mlx->width)
			exit(0);
	}
	mlx->height = y;
	if (mlx->height <= 1 || mlx->width <= 1)
		exit(0);
	close(fd);
}
