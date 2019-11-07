/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:55:19 by knedzing          #+#    #+#             */
/*   Updated: 2018/08/15 14:48:35 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

void		init1(t_draw *draw, t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, W, H);
	mlx->dat = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl, &mlx->endian);
	mlx->bpp /= 8;
	draw->pos[0] = mlx->player[0];
	draw->pos[1] = mlx->player[1];
	draw->dir[0] = -1 * cos(mlx->angle);
	draw->dir[1] = -1 * sin(mlx->angle);
	draw->plane[0] = -0.66 * sin(mlx->angle);
	draw->plane[1] = 0.66 * cos(mlx->angle);
	draw->x = -1;
	draw->y = -1;
}

void		init2(t_draw *draw, int x)
{
	draw->cam[0] = 2 * x / (double)W - 1;
	draw->raydir[0] = draw->dir[0] + draw->plane[0] * draw->cam[0];
	draw->raydir[1] = draw->dir[1] + draw->plane[1] * draw->cam[0];
	draw->map[0] = (int)draw->pos[0];
	draw->map[1] = (int)draw->pos[1];
	draw->dd[0] = fabs(1 / draw->raydir[0]);
	draw->dd[1] = fabs(1 / draw->raydir[1]);
	draw->hit = 0;
}
