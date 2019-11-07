/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 15:46:48 by knedzing          #+#    #+#             */
/*   Updated: 2018/08/15 14:59:00 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

int		fi(char **line)
{
	int c;

	c = -1;
	while (line[++c])
	{
		free(line[c]);
	}
	free(line);
	return (1);
}

int		arr_len(char **str)
{
	int c;

	c = -1;
	while (str[++c])
		;
	return (c);
}

void	init(t_mlx *mlx)
{
	char	**split;
	char	*line;
	int		fd;
	int		x;
	int		y;

	errors(mlx);
	if ((fd = open(mlx->f_n, O_RDONLY)) < 0)
		exit(0);
	y = 0;
	while (get_next_line(fd, &line) == 1 && ++y < mlx->height - 1)
	{
		x = 1;
		split = ft_strsplit(line, ' ');
		free(line);
		if (ft_atoi(split[++x]) == 0 && x < mlx->width - 1)
		{
			mlx->player[0] = y + 0.5 - 1;
			mlx->player[1] = x + 0.5;
		}
		fi(split);
	}
	free(line);
	if (mlx->player[0] == 0 || mlx->player[1] == 0)
		exit(0);
}

int		get_map(t_mlx *mlx)
{
	char	*line;
	int		c;
	int		fd;
	int		len;
	char	**split;

	if ((fd = open(mlx->f_n, O_RDONLY)) < 0)
		return (0);
	init(mlx);
	if (!(mlx->w_map = (int**)malloc(sizeof(int**) * mlx->height)))
		return (0);
	c = -1;
	while (get_next_line(fd, &line) == 1 && (len = mlx->width))
	{
		split = ft_strsplit(line, ' ');
		free(line);
		if (!(mlx->w_map[++c] = (int*)malloc(sizeof(int*) * len)) && fi(split))
			return (0);
		while (--len >= 0)
			mlx->w_map[c][len] = ft_atoi(split[len]);
		fi(split);
	}
	close(fd);
	return (1);
}

int		main(int ac, char **av)
{
	t_mlx		*mlx;

	if (ac == 2)
	{
		if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
			return (0);
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, W, H, "Wolf3D");
		mlx->f_n = av[1];
		mlx->angle = 0;
		mlx->r = 4;
		if (!get_map(mlx))
		{
			write(1, "Error, invalid file name\n", 25);
			return (0);
		}
		drawer(mlx);
		mlx_hook(mlx->win, 2, 0, handle_key_press, mlx);
		mlx_hook(mlx->win, 17, 0, cross, mlx);
		mlx_loop(mlx->mlx);
	}
	else
		write(1, "Error, no map\n", 14);
	return (0);
}
