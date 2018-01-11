/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:15:23 by pierre            #+#    #+#             */
/*   Updated: 2018/01/11 15:18:26 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf.h"
#include <matrix.h>

int				trans_max(t_fdf *fdf)
{
	t_matrix	*m;

	m = ft_mtx_new();
	m->tz = MOVE_TRANS * fdf->d_plan / 400.0;
	calc_foreach(fdf, &m);
	expose_win(fdf);
	return (TRUE);
}

int				trans_min(t_fdf *fdf)
{
	t_matrix	*m;

	m = ft_mtx_new();
	m->tz = -1 * MOVE_TRANS * fdf->d_plan / 400.0;
	calc_foreach(fdf, &m);
	expose_win(fdf);
	return (TRUE);
}

int				peak_up(t_fdf *fdf)
{
	t_matrix	*m;

	m = ft_mtx_new();
	m->zz = 2.0;
	calc_foreach(fdf, &m);
	expose_win(fdf);
	return (TRUE);
}

int				peak_down(t_fdf *fdf)
{
	t_matrix	*m;

	m = ft_mtx_new();
	m->zz = (1.0 / 2.0);
	calc_foreach(fdf, &m);
	expose_win(fdf);
	return (TRUE);
}
