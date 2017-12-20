/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_tr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:12:13 by pierre            #+#    #+#             */
/*   Updated: 2017/12/20 18:54:29 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf.h"
#include <matrix.h>

int				trans_up(t_fdf *fdf)
{
	t_matrix	*m;

	m = ft_mtx_new();
	m->ty = MOVE_TRANS;
	calc_foreach(fdf, &m);
	expose_win(fdf);
	return (TRUE);
}

int				trans_down(t_fdf *fdf)
{
	t_matrix	*m;

	m = ft_mtx_new();
	m->ty = -MOVE_TRANS;
	calc_foreach(fdf, &m);
	expose_win(fdf);
	return (TRUE);
}

int				trans_right(t_fdf *fdf)
{
	t_matrix	*m;

	m = ft_mtx_new();
	m->tx = MOVE_TRANS;
	calc_foreach(fdf, &m);
	expose_win(fdf);
	return (TRUE);
}

int				trans_left(t_fdf *fdf)
{
	t_matrix	*m;

	m = ft_mtx_new();
	m->tx = -MOVE_TRANS;
	calc_foreach(fdf, &m);
	expose_win(fdf);
	return (TRUE);
}
