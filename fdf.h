/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:15:18 by pierre            #+#    #+#             */
/*   Updated: 2017/12/16 15:46:13 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

#include "vector.h"

# define				D_PLAN			400
# define				D_USER			400
# define				COEF_PEAK		5
# define				COEF_GAP		40
# define				COLOR			0xFFFFFF
# define				SIZE_WINDOWS_X	600
# define				SIZE_WINDOWS_Y	400

# define				K_ESCAPE		65307
# define				K_LEFT			65361
# define				K_UP			65362
# define				K_RIGHT			65363
# define				K_DOWN			65364

# define				PI				3.14159265358979323846

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
int			init_fdf(t_fdf *fdf, char *s);
int			init_mlx(t_fdf *fdf);
int			free_fdf(t_fdf *fdf);
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
#endif
