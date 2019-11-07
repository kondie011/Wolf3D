/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:51:22 by knedzing          #+#    #+#             */
/*   Updated: 2018/08/10 13:34:16 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

int			get_sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

void		init_drawl(t_drawl *mdraw, t_mlx *mmlx)
{
	mdraw->x1 = mmlx->p1[0];
	mdraw->x2 = mmlx->p2[0];
	mdraw->y1 = mmlx->p1[1];
	mdraw->y2 = mmlx->p2[1];
	mdraw->x = mdraw->x1;
	mdraw->y = mdraw->y1;
	mdraw->dx = abs(mdraw->x2 - mdraw->x1);
	mdraw->dy = abs(mdraw->y2 - mdraw->y1);
	mdraw->s1 = get_sign(mdraw->x2 - mdraw->x1);
	mdraw->s2 = get_sign(mdraw->y2 - mdraw->y1);
	mdraw->swp = 0;
}

void		swap_em(t_drawl *mdraw)
{
	int tmp;

	if (mdraw->dx < mdraw->dy)
	{
		tmp = mdraw->dx;
		mdraw->dx = mdraw->dy;
		mdraw->dy = tmp;
		mdraw->swp = 1;
	}
}

void		put_pixel(t_mlx *mlx, int x, int y, int col)
{
	if (x >= 0 && y >= 0 && x < W && y < H)
	{
		*(unsigned int *)(mlx->dat + (x * mlx->bpp) + (y * mlx->sl)) = col;
	}
}

void		draw_line(t_mlx *mmlx, int color)
{
	t_drawl *mdraw;

	mdraw = (t_drawl*)malloc(sizeof(t_drawl));
	init_drawl(mdraw, mmlx);
	swap_em(mdraw);
	mdraw->p = 2 * mdraw->dy - mdraw->dx;
	mdraw->i = -1;
	while (++mdraw->i < mdraw->dx)
	{
		put_pixel(mmlx, mdraw->x, mdraw->y, color);
		while (mdraw->p >= 0)
		{
			mdraw->p = mdraw->p - 2 * mdraw->dx;
			if (mdraw->swp)
				mdraw->x += mdraw->s1;
			else
				mdraw->y += mdraw->s2;
		}
		mdraw->p = mdraw->p + 2 * mdraw->dy;
		if (mdraw->swp)
			mdraw->y += mdraw->s2;
		else
			mdraw->x += mdraw->s1;
	}
	free(mdraw);
}
