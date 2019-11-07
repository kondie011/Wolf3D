/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 18:04:01 by knedzing          #+#    #+#             */
/*   Updated: 2018/08/15 15:08:46 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

int		is_inbound(t_mlx *mlx, double x, double y, int frm)
{
	if (frm == 0)
		if (x + (mlx->draw.dir[0] / mlx->r) * mlx->s > 1.0 &&
				x + (mlx->draw.dir[0] / mlx->r) * mlx->s < mlx->height - 2)
			return (1);
	if (frm == 1)
		if (y + (mlx->draw.dir[1] / mlx->r) * mlx->s > 1.0 &&
				y + (mlx->draw.dir[1] / mlx->r) * mlx->s < mlx->width - 2)
			return (1);
	return (0);
}

void	move_up(t_mlx *mlx, double x, double y)
{
	mlx->s = 1;
	if (is_inbound(mlx, x, y, 0) &&
			mlx->w_map[(int)(x + mlx->draw.dir[0] / mlx->r)][(int)y] == 0)
		mlx->player[0] += mlx->draw.dir[0] / mlx->r;
	else
		write(1, "\a", 1);
	x = mlx->player[0];
	if (is_inbound(mlx, x, y, 1) &&
			mlx->w_map[(int)x][(int)(y + mlx->draw.dir[1] / mlx->r)] == 0)
		mlx->player[1] += mlx->draw.dir[1] / mlx->r;
	else
		write(1, "\a", 1);
}

void	handle_movements(int key, t_mlx *m)
{
	double x;
	double y;

	if ((key == 125 || key == 126) && (x = m->player[0]) > -1)
	{
		if ((y = m->player[1]) == m->player[1] && key == 125)
		{
			m->s = -1;
			if (is_inbound(m, x, y, 0) &&
					m->w_map[(int)(x - m->draw.dir[0] / m->r)][(int)y] == 0)
				m->player[0] -= m->draw.dir[0] / m->r;
			else
				write(1, "\a", 1);
			x = m->player[0];
			if (is_inbound(m, x, y, 1) &&
					m->w_map[(int)x][(int)(y - m->draw.dir[1] / m->r)] == 0)
				m->player[1] -= m->draw.dir[1] / m->r;
			else
				write(1, "\a", 1);
		}
		else if (key == 126)
			move_up(m, x, y);
		mlx_clear_window(m->mlx, m->win);
		drawer(m);
	}
}

void	handle_rot(int key, t_mlx *mlx)
{
	if (key == 123 || key == 124)
	{
		if (key == 124)
			mlx->angle -= 0.1;
		else if (key == 123)
			mlx->angle += 0.1;
		mlx_clear_window(mlx->mlx, mlx->win);
		drawer(mlx);
	}
}

int		handle_key_press(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	else if (key == 257)
	{
		if (mlx->r == 1)
			mlx->r = 4;
		else
			mlx->r = 1;
	}
	handle_movements(key, mlx);
	handle_rot(key, mlx);
	return (0);
}
