/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:15:18 by pierre            #+#    #+#             */
/*   Updated: 2017/12/12 16:51:11 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

#include "vector.h"

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	t_vect				*center;
	int					col;
	int					row;
	t_vect				**grid;
	int					coef_gap_vector;
	int					coef_top;
}						t_fdf;

int			check_dim_grid(t_fdf *a, char *file);
int			fill_vector(t_fdf *a, char *file);
int			set_vector(t_fdf *a, int x, int y, int z);
int			fill_grid_vector(t_fdf *a, int fd);

#endif
