/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:06:42 by knedzing          #+#    #+#             */
/*   Updated: 2018/08/15 14:49:02 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

void		choose_color(t_draw *draw)
{
	if (draw->side == 1)
	{
		if ((draw->step[0] == -1 && draw->step[1] == -1) ||
				(draw->step[0] == 1 && draw->step[1] == -1))
			draw->color = GREEN;
		if ((draw->step[0] == 1 && draw->step[1] == 1) ||
				(draw->step[0] == -1 && draw->step[1] == 1))
			draw->color = RED;
	}
	else if ((draw->step[0] == -1 && draw->step[1] == -1) ||
			(draw->step[0] == -1 && draw->step[1] == 1))
		draw->color = BLUE;
	else
		draw->color = YELLOW;
}

void		calc_raydist(t_draw *draw)
{
	if (draw->raydir[0] < 0)
	{
		draw->step[0] = -1;
		draw->sd[0] = (draw->pos[0] - draw->map[0]) * draw->dd[0];
	}
	else
	{
		draw->step[0] = 1;
		draw->sd[0] = (draw->map[0] + 1 - draw->pos[0]) * draw->dd[0];
	}
	if (draw->raydir[1] < 0)
	{
		draw->step[1] = -1;
		draw->sd[1] = (draw->pos[1] - draw->map[1]) * draw->dd[1];
	}
	else
	{
		draw->step[1] = 1;
		draw->sd[1] = (draw->map[1] + 1 - draw->pos[1]) * draw->dd[1];
	}
}

void		find_wall(t_mlx *mlx)
{
	while (!mlx->draw.hit && mlx->draw.map[0] < mlx->height - 2 &&
			mlx->draw.map[0] > 0 && mlx->draw.map[1] > 0 &&
			mlx->draw.map[1] < mlx->width - 2)
	{
		if (mlx->draw.sd[0] < mlx->draw.sd[1])
		{
			mlx->draw.sd[0] += mlx->draw.dd[0];
			mlx->draw.map[0] += mlx->draw.step[0];
			mlx->draw.side = 0;
		}
		else
		{
			mlx->draw.sd[1] += mlx->draw.dd[1];
			mlx->draw.map[1] += mlx->draw.step[1];
			mlx->draw.side = 1;
		}
		if (mlx->w_map[mlx->draw.map[0]][mlx->draw.map[1]] > 0)
			mlx->draw.hit = 1;
	}
}

void		draw_everything(t_mlx *mlx)
{
	mlx->p1[1] = -mlx->draw.line_height / 2 + H / 2;
	if (mlx->p1[1] < 0)
		mlx->p1[1] = -1;
	mlx->p2[1] = mlx->draw.line_height / 2 + H / 2;
	if (mlx->p2[1] > H)
		mlx->p2[1] = H;
	mlx->p1[0] = mlx->draw.x;
	mlx->p2[0] = mlx->draw.x;
	choose_color(&mlx->draw);
	draw_line(mlx, mlx->draw.color);
	mlx->p2[1] = -1;
	draw_line(mlx, 0x00FFFF);
}

void		drawer(t_mlx *mlx)
{
	t_draw *draw;

	draw = &mlx->draw;
	init1(draw, mlx);
	while (++mlx->draw.x < W)
	{
		init2(draw, mlx->draw.x);
		calc_raydist(draw);
		find_wall(mlx);
		if (draw->side == 0)
			draw->pwd = (draw->map[0] - draw->pos[0] +
					(1 - draw->step[0]) / 2) / draw->raydir[0];
		else
			draw->pwd = (draw->map[1] - draw->pos[1] +
					(1 - draw->step[1]) / 2) / draw->raydir[1];
		if (draw->pwd != 0)
			draw->line_height = (int)(H / draw->pwd);
		draw_everything(mlx);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img);
}
