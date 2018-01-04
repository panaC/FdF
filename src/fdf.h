/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:15:18 by pierre            #+#    #+#             */
/*   Updated: 2018/01/04 22:14:57 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include <vector.h>
# include <matrix.h>
# include <arg.h>

# define D_PLAN			400
# define D_USER			400
# define COEF_PEAK		10
# define COEF_GAP		40
# define COLOR			0xFFFFFF
# define SIZE_X			600
# define SIZE_Y			400
# ifdef __linux__
#  define K_ESCAPE		65307
#  define K_LEFT		65361
#  define K_UP			65362
#  define K_RIGHT		65363
#  define K_DOWN		65364
#  define K_A			'a'
#  define K_Z			'z'
#  define K_S			's'
#  define K_X			'x'
#  define K_H			'h'
#  define K_J			'j'
#  define K_K			'k'
#  define K_L			'l'
# endif
# ifdef __APPLE__
#  define K_ESCAPE		53
#  define K_LEFT		123
#  define K_UP			126
#  define K_RIGHT		124
#  define K_DOWN		125
#  define K_A			0
#  define K_Z			6
#  define K_S			1
#  define K_X			7
#  define K_H			4
#  define K_J			38
#  define K_K			40
#  define K_L			37
# endif
# define PI				3.14159265358979323846
# define MOVE_TRANS		20

typedef struct s_tab	t_tab;
typedef struct s_fdf	t_fdf;

/*
** dot 3D plan
** dot 2D projection
** location
** color of the top dot
*/

typedef struct			s_dot
{
	t_vect				*dot3;
	t_vect				*dot2;
	int					x;
	int					y;
	t_uint32			color;
}						t_dot;

/*
** key event
*/

struct					s_tab
{
	int					key;
	int					(*ft)(t_fdf *);
};

/*
** arg
** mlx
** map
** grid
** param projection pinhole
** tab key event
*/

struct					s_fdf
{
	t_arg				*arg;
	void				*mlx;
	void				*win;
	int					size_win_x;
	int					size_win_y;
	t_vect				*center;
	char				*title;
	char				*file;
	int					col;
	int					row;
	int					coef_gap_vector;
	int					coef_top;
	int					d_plan;
	int					d_user;
	t_uint32			color;
	t_dot				**grid;
	t_vect				*unit0;
	t_vect				*plan0;
	t_vect				*user0;
	t_tab				ev[12];
	int					size_map;
};

/*
** parser.c
*/
int						check_dim_grid(t_fdf *a);
int						fill_vector(t_fdf *a);
int						fill_grid_vector(t_fdf *a, int fd);
/*
** it.c
*/
int						mouse_win(int x, int y, t_fdf *fdf);
int						key_win(int but, t_fdf *fdf);
int						expose_win(t_fdf *fdf);
/*
** draw.c
*/
void					line(t_fdf *fdf, t_dot *s, t_dot *e);
int						draw_line(t_fdf *a, t_vect *s1, t_vect *s2, int color);
int						draw_grid(t_fdf *fdf);
/*
** init.c
*/
int						init_tab(t_fdf *fdf);
int						init_fdf(t_fdf *fdf);
int						init_mlx(t_fdf *fdf);
int						free_fdf(t_fdf **fdf);
t_dot					*dot_new(t_vect *s1, t_vect *s2, t_vect *pos,
		t_uint32 color);
/*
** calcul.c
*/
int						calc_matrix_init(t_fdf *fdf);
t_vect					*calc_3d_projection(t_fdf *fdf);
void					calc_foreach(t_fdf *fdf, t_matrix **m);
/*
** calc_rot.c
*/
int						calc_matrix_left(t_fdf *fdf);
int						calc_matrix_right(t_fdf *fdf);
int						calc_matrix_up(t_fdf *fdf);
int						calc_matrix_down(t_fdf *fdf);
/*
** calc_tr.c
*/
int						trans_up(t_fdf *fdf);
int						trans_down(t_fdf *fdf);
int						trans_right(t_fdf *fdf);
int						trans_left(t_fdf *fdf);
/*
** calc_size.c
*/
int						trans_max(t_fdf *fdf);
int						trans_min(t_fdf *fdf);
int						peak_down(t_fdf *fdf);
int						peak_up(t_fdf *fdf);
/*
** arg.c
*/
t_bool					check_arg(t_fdf *fdf, int ac, char **av);
/*
** color.c
*/
t_uint32				get_color(t_fdf *fdf, char *str);
t_uint32				*set_tab_col_deg(t_uint32 sc, t_uint32 ec, int d);
t_uint32				col_deg(t_uint32 *tab, int i);

#endif
