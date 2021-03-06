/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 10:04:19 by pierre            #+#    #+#             */
/*   Updated: 2018/01/15 18:55:57 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf.h"
#include <matrix.h>
#include <math.h>

static int		calc_matrix_init_rot(t_fdf *fdf)
{
	t_matrix	*m;

	m = ft_mtx_new();
	m->yy = cos(PI / 6.0);
	m->yz = sin(PI / 6.0);
	m->zy = -sin(PI / 6.0);
	m->zz = cos(PI / 6.0);
	calc_foreach(fdf, &m);
	return (TRUE);
}

int				calc_matrix_init(t_fdf *fdf)
{
	t_matrix	*m;

	m = ft_mtx_new();
	m->xx = fdf->coef_gap_vector;
	m->yy = fdf->coef_gap_vector;
	m->zz = fdf->coef_top;
	m->tx = (int)(fdf->center->x - ((fdf->col / 2) * fdf->coef_gap_vector));
	m->ty = (int)(fdf->center->y - ((fdf->row / 2) * fdf->coef_gap_vector));
	calc_foreach(fdf, &m);
	calc_matrix_init_rot(fdf);
	return (TRUE);
}

void			calc_foreach(t_fdf *fdf, t_matrix **m)
{
	int			i;

	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, *m);
		i++;
	}
	ft_memdel((void**)m);
}

t_vect			*calc_3d_projection(t_fdf *fdf)
{
	t_vect		*ret;
	t_vect		*v;
	int			i;

	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		v = fdf->grid[i]->dot3;
		ret = ft_vect_new(((fdf->user0->z - v->z) <= 0) ?
				(v->x - fdf->center->x) :
				((double)((double)fdf->d_user / (double)(fdf->user0->z - v->z))
				* ((double)(v->x - fdf->center->x)) + ((double)fdf->center->x)),
				((fdf->user0->z - v->z) <= 0) ? (v->y - fdf->center->y) :
				((double)((double)fdf->d_user / (double)(fdf->user0->z - v->z))
				* ((double)(v->y - fdf->center->y)) + ((double)fdf->center->y)),
				fdf->plan0->z);
		ft_memdel((void**)&(fdf->grid[i]->dot2));
		fdf->grid[i]->dot2 = ret;
		i++;
	}
	return (ret);
}
