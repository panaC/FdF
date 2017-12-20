/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:15:18 by pierre            #+#    #+#             */
/*   Updated: 2017/12/20 11:52:53 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

#include "vector.h"
#include <arg.h>

# define				D_PLAN			400
# define				D_USER			400
# define				COEF_PEAK		10
# define				COEF_GAP		40
# define				COLOR			0xFFFFFF
# define				SIZE_X			600
# define				SIZE_Y			400

# define				K_ESCAPE		65307
# define				K_LEFT			65361
# define				K_UP			65362
# define				K_RIGHT			65363
# define				K_DOWN			65364

# define				PI				3.14159265358979323846

# define				MOVE_TRANS		20

typedef struct			s_dot
{
	/*
	 * dot 3d plan
	 */
	t_vect				*dot3;
	/*
	 * dot 2d projection
	 */
	t_vect				*dot2;
	/*
	 * localisation
	 */
	int					x;
	int					y;
	/*
	 * color of the dot top
	 */
	int					color;
}						t_dot;

typedef struct			s_fdf
{
	/*
	 * arg
	 */
	t_arg				*arg;
	/*
	 * mlx
	 */
	void				*mlx;
	void				*win;
	int					size_win_x;
	int					size_win_y;
	t_vect				*center;
	char				*title;
	/*
	 * map
	 */
	char				*file;
	int					col;
	int					row;
	int					coef_gap_vector;
	int					coef_top;
	int					d_plan;
	int					d_user;
	int					color;
	/*
	 * grid
	 */
	t_dot				**grid;
	/*
	 * param projection pinhole
	 */
	t_vect				*unit0;
	t_vect				*plan0;
	t_vect				*user0;
}						t_fdf;

/*
 * parser.c
 */
int			check_dim_grid(t_fdf *a);
int			fill_vector(t_fdf *a);
int			set_vector(t_fdf *a, int x, int y, int z);
int			fill_grid_vector(t_fdf *a, int fd);
/*
 * it.c
 */
int			mouse_win(int x, int y, t_fdf *fdf);
int			key_win(int but, t_fdf *fdf);
int			expose_win(t_fdf *fdf);
/*
 * draw.c
 */
void		line(t_fdf *a, t_vect *s, t_vect *e, int color);
int			draw_line(t_fdf *a, t_vect *s1, t_vect *s2, int color);
int			draw_grid(t_fdf *fdf);
/*
 * init.c
 */
int			init_fdf(t_fdf *fdf);
int			init_mlx(t_fdf *fdf);
int			free_fdf(t_fdf **fdf);
t_dot		*dot_new(t_vect *s1, t_vect *s2, t_vect *pos, int color);
/*
 * calcul.c
 */
int			calc_matrix_init(t_fdf *fdf);
t_vect		*calc_3d_projection(t_fdf *fdf);
int			calc_matrix_left(t_fdf *fdf);
int			calc_matrix_right(t_fdf *fdf);
int			calc_matrix_up(t_fdf *fdf);
int			calc_matrix_down(t_fdf *fdf);
int			trans_up(t_fdf *fdf);
int			trans_down(t_fdf *fdf);
int			trans_right(t_fdf *fdf);
int			trans_left(t_fdf *fdf);
int			trans_max(t_fdf *fdf);
int			trans_min(t_fdf *fdf);
int			peak_down(t_fdf *fdf);
int			peak_up(t_fdf *fdf);
/*
 * arg.c
 */
t_bool				check_arg(t_fdf *fdf, int ac, char **av);

#endif
