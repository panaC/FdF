/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_tr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:12:13 by pierre            #+#    #+#             */
/*   Updated: 2017/12/20 18:13:38 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf.h"
#include <matrix.h>

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
