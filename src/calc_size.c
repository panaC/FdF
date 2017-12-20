/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:15:23 by pierre            #+#    #+#             */
/*   Updated: 2017/12/20 18:15:52 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf.h"
#include <matrix.h>

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
