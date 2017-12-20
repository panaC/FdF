/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 10:04:19 by pierre            #+#    #+#             */
/*   Updated: 2017/12/20 11:13:08 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"
#include <matrix.h>
#include <math.h>

#include <stdio.h>

int				calc_matrix_init(t_fdf *fdf)
{
	t_matrix	*m;
	int			i;

	m = ft_mtx_new();
	m->xx = fdf->coef_gap_vector;
	m->yy = fdf->coef_gap_vector;
	m->zz = fdf->coef_top;
	m->tx = (int)(fdf->center->x - ((fdf->col / 2) * fdf->coef_gap_vector));
	m->ty = (int)(fdf->center->y - ((fdf->row / 2) * fdf->coef_gap_vector));
	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, m);
		i++;
	}
	m = ft_mtx_identity(m);
	m->yy *= cos(PI / 6.0);
	m->yz = sin(PI / 6.0);
	m->zy = - sin(PI / 6.0);
	m->zz *= cos(PI / 6.0);
	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, m);
		i++;
	}
	return (TRUE);
}

int				calc_matrix_left(t_fdf *fdf)
{
	t_matrix	*m;
	int			i;

	m = ft_mtx_new();
	m->xx = cos(PI / 18.0);
	m->xz = - sin(PI / 18.0);
	m->zx = sin(PI / 18.0);
	m->zz = cos(PI / 18.0);
	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, m);
		i++;
	}
	expose_win(fdf);
	return (TRUE);
}

int				calc_matrix_right(t_fdf *fdf)
{
	t_matrix	*m;
	int			i;

	m = ft_mtx_new();
	m->xx = cos(- PI / 18.0);
	m->xz = - sin(- PI / 18.0);
	m->zx = sin(- PI / 18.0);
	m->zz = cos(- PI / 18.0);
	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, m);
		i++;
	}
	expose_win(fdf);
	return (TRUE);
}

int				calc_matrix_up(t_fdf *fdf)
{
	t_matrix	*m;
	int			i;

	m = ft_mtx_new();
	m->yy = cos(PI / 18.0);
	m->yz = sin(PI / 18.0);
	m->zy = - sin(PI / 18.0);
	m->zz = cos(PI / 18.0);
	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, m);
		i++;
	}
	expose_win(fdf);
	return (TRUE);
}

int				calc_matrix_down(t_fdf *fdf)
{
	t_matrix	*m;
	int			i;

	m = ft_mtx_new();
	m->yy = cos(- PI / 18.0);
	m->yz = sin(- PI / 18.0);
	m->zy = - sin(- PI / 18.0);
	m->zz = cos(- PI / 18.0);
	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, m);
		i++;
	}
	expose_win(fdf);
	return (TRUE);
}

int				trans_up(t_fdf *fdf)
{
	t_matrix	*m;
	int			i;

	m = ft_mtx_new();
	m->ty = MOVE_TRANS;
	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, m);
		i++;
	}
	expose_win(fdf);
	return (TRUE);
}

int				trans_down(t_fdf *fdf)
{
	t_matrix	*m;
	int			i;

	m = ft_mtx_new();
	m->ty = - MOVE_TRANS;
	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, m);
		i++;
	}
	expose_win(fdf);
	return (TRUE);
}

int				trans_right(t_fdf *fdf)
{
	t_matrix	*m;
	int			i;

	m = ft_mtx_new();
	m->tx = MOVE_TRANS;
	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, m);
		i++;
	}
	expose_win(fdf);
	return (TRUE);
}

int				trans_left(t_fdf *fdf)
{
	t_matrix	*m;
	int			i;

	m = ft_mtx_new();
	m->tx = - MOVE_TRANS;
	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, m);
		i++;
	}
	expose_win(fdf);
	return (TRUE);
}

int				trans_max(t_fdf *fdf)
{
	t_matrix	*m;
	int			i;

	m = ft_mtx_new();
	m->tz = MOVE_TRANS;
	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, m);
		i++;
	}
	expose_win(fdf);
	return (TRUE);
}

int				trans_min(t_fdf *fdf)
{
	t_matrix	*m;
	int			i;

	m = ft_mtx_new();
	m->tz = - MOVE_TRANS;
	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, m);
		i++;
	}
	expose_win(fdf);
	return (TRUE);
}

int				peak_up(t_fdf *fdf)
{
	t_matrix	*m;
	int			i;

	m = ft_mtx_new();
	m->zz = 2.0;
	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, m);
		i++;
	}
	expose_win(fdf);
	return (TRUE);
}

int				peak_down(t_fdf *fdf)
{
	t_matrix	*m;
	int			i;

	m = ft_mtx_new();
	m->zz = (1.0 / 2.0);
	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		fdf->grid[i]->dot3 = ft_mtx_mul_vec(fdf->grid[i]->dot3, m);
		i++;
	}
	expose_win(fdf);
	return (TRUE);
}

t_vect			*calc_3d_projection(t_fdf *fdf)
{
	t_vect		*ret;
	t_vect		*v;
	int			i;
	double		tmp;

	i = 0;
	while (i < (fdf->col * fdf->row))
	{
		v = fdf->grid[i]->dot3;
		ret = ft_vect_new(0, 0, 0);
		tmp = (double)((double)D_USER / (double)(fdf->user0->z - v->z));
		tmp *= (double)(v->x - fdf->center->x);
		tmp += (double)fdf->center->x;
		ret->x = (int)tmp;
//		printf("tmp : %f\n", tmp);
		tmp = (double)((double)D_USER / (double)(fdf->user0->z - v->z));
		tmp *= (double)(v->y - fdf->center->y);
		tmp += (double)fdf->center->y;
		ret->y = (int)tmp;
		ret->z = fdf->plan0->z;
		fdf->grid[i]->dot2 = ret;
//		printf("v : \n");
//		print_vect(v);
//		printf("r : \n");
//		print_vect(ret);
		i++;
	}
	return (ret);
}
