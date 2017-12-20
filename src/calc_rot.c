/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:09:52 by pierre            #+#    #+#             */
/*   Updated: 2017/12/20 18:49:34 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <matrix.h>
#include <math.h>
#include "fdf.h"

int				calc_matrix_left(t_fdf *fdf)
{
	t_matrix	*m;

	m = ft_mtx_new();
	m->xx = cos(PI / 18.0);
	m->xz = - sin(PI / 18.0);
	m->zx = sin(PI / 18.0);
	m->zz = cos(PI / 18.0);
	calc_foreach(fdf, &m);
	expose_win(fdf);
	return (TRUE);
}

int				calc_matrix_right(t_fdf *fdf)
{
	t_matrix	*m;

	m = ft_mtx_new();
	m->xx = cos(- PI / 18.0);
	m->xz = - sin(- PI / 18.0);
	m->zx = sin(- PI / 18.0);
	m->zz = cos(- PI / 18.0);
	calc_foreach(fdf, &m);
	expose_win(fdf);
	return (TRUE);
}

int				calc_matrix_up(t_fdf *fdf)
{
	t_matrix	*m;

	m = ft_mtx_new();
	m->yy = cos(PI / 18.0);
	m->yz = sin(PI / 18.0);
	m->zy = - sin(PI / 18.0);
	m->zz = cos(PI / 18.0);
	calc_foreach(fdf, &m);
	expose_win(fdf);
	return (TRUE);
}

int				calc_matrix_down(t_fdf *fdf)
{
	t_matrix	*m;

	m = ft_mtx_new();
	m->yy = cos(- PI / 18.0);
	m->yz = sin(- PI / 18.0);
	m->zy = - sin(- PI / 18.0);
	m->zz = cos(- PI / 18.0);
	calc_foreach(fdf, &m);
	expose_win(fdf);
	return (TRUE);
}
