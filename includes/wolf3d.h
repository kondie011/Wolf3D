/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 15:51:33 by knedzing          #+#    #+#             */
/*   Updated: 2018/08/15 14:52:09 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define W 1500
# define H 900
# define TH 64
# define TW 64
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define TH 64
# define TW 64
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "../get_next_line/libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct			s_drawl
{
	int x;
	int y;
	int dx;
	int dy;
	int swp;
	int s1;
	int s2;
	int p;
	int i;
	int x1;
	int x2;
	int y1;
	int y2;
}						t_drawl;
typedef struct			s_draw
{
	double	pos[2];
	double	dir[2];
	double	plane[2];
	double	cam[2];
	double	raydir[2];
	int		map[2];
	int		side;
	double	sd[2];
	double	dd[2];
	double	pwd;
	int		step[2];
	int		hit;
	int		line_height;
	int		color;
	int		x;
	int		y;
	int		c;
}						t_draw;
typedef struct			s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*dat;
	int				bpp;
	int				sl;
	int				endian;
	char			*f_n;
	int				**w_map;
	int				width;
	int				height;
	int				p1[2];
	int				p2[2];
	double			angle;
	double			player[2];
	int				s;
	double			r;
	struct s_draw	draw;
}						t_mlx;
int						cross(int key, t_mlx *mlx);
void					tex_calc(t_mlx *mlx);
int						fi(char **line);
void					errors(t_mlx *mlx);
int						get_map(t_mlx *mlx);
void					choose_color(t_draw *draw);
int						arr_len(char **str);
void					init1(t_draw *draw, t_mlx *mlx);
void					init2(t_draw *draw, int x);
void					drawer(t_mlx *mlx);
int						get_sign(int x);
void					init_drawl(t_drawl *mdraw, t_mlx *mmlx);
void					swap_em(t_drawl *mdraw);
void					draw_line(t_mlx *mmlx, int color);
int						handle_key_press(int key, t_mlx *mmlx);
void					movements(int key, t_mlx *mmlx);

#endif
