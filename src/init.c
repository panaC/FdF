/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:38:39 by pierre            #+#    #+#             */
/*   Updated: 2018/01/15 18:02:20 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#ifdef __linux__
# include <mlx_int.h>
#endif
#include <libft.h>
#include <vector.h>
#include "fdf.h"

#include <stdio.h>

int			init_tab(t_fdf *fdf)
{
	(fdf->ev[0]).key = K_LEFT;
	(fdf->ev[0]).ft = calc_matrix_left;
	(fdf->ev[1]).key = K_RIGHT;
	(fdf->ev[1]).ft = calc_matrix_right;
	(fdf->ev[2]).key = K_UP;
	(fdf->ev[2]).ft = calc_matrix_up;
	(fdf->ev[3]).key = K_DOWN;
	(fdf->ev[3]).ft = calc_matrix_down;
	(fdf->ev[4]).key = K_K;
	(fdf->ev[4]).ft = trans_up;
	(fdf->ev[5]).key = K_J;
	(fdf->ev[5]).ft = trans_down;
	(fdf->ev[6]).key = K_H;
	(fdf->ev[6]).ft = trans_left;
	(fdf->ev[7]).key = K_L;
	(fdf->ev[7]).ft = trans_right;
	(fdf->ev[8]).key = K_A;
	(fdf->ev[8]).ft = trans_max;
	(fdf->ev[9]).key = K_Z;
	(fdf->ev[9]).ft = trans_min;
	(fdf->ev[10]).key = K_S;
	(fdf->ev[10]).ft = peak_up;
	(fdf->ev[11]).key = K_X;
	(fdf->ev[11]).ft = peak_down;
	return (TRUE);
}

int			init_fdf(t_fdf *fdf)
{
	fdf->is_color = !(ft_search_param(fdf->arg->long_param, NULL, "no-color"));
	fdf->is_auto = !(ft_search_param(fdf->arg->long_param, NULL, "no-auto"));
	ft_setparam_int(fdf->arg, "coef-gap", &(fdf->coef_gap_vector), COEF_GAP);
	ft_setparam_int(fdf->arg, "coef-top", &(fdf->coef_top), COEF_PEAK);
	ft_setparam_int(fdf->arg, "d-plan", &(fdf->d_plan), D_PLAN);
	ft_setparam_int(fdf->arg, "d-user", &(fdf->d_user), D_USER);
	ft_setparam_hex(fdf->arg, "color", &(fdf->color), 0xFFFFFFF);
	ft_setparam_doubleint(fdf->arg, "size-win", &(fdf->size_win_x), SIZE_X);
	ft_setparam_doubleint(fdf->arg, "size-win", &(fdf->size_win_y), SIZE_Y);
	fdf->title = ft_strnew(50);
	fdf->file = ft_strnew(fdf->arg->data_param->content_size + 1);
	fdf->file = (t_string)ft_memcpy(fdf->file,
			(t_string)fdf->arg->data_param->content,
			fdf->arg->data_param->content_size);
	ft_strlcat(fdf->title, "fdf -> ", 50);
	ft_strlcat(fdf->title, fdf->file, 50);
	fdf->grid = NULL;
	init_tab(fdf);
	return (TRUE);
}

/*
** mlx_hook(fdf->win, MotionNotify, PointerMotionMask, mouse_win, fdf);
*/

int			init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (FALSE);
	fdf->win = mlx_new_window(fdf->mlx, fdf->size_win_x, fdf->size_win_y,
			fdf->title);
	mlx_expose_hook(fdf->win, expose_win, fdf);
	mlx_key_hook(fdf->win, key_win, fdf);
	return (TRUE);
}

int			init_auto(t_fdf *fdf)
{
	int				size_win;
	int				size_fil;

	if (fdf->is_auto)
	{
		size_win = ((fdf->size_win_x > fdf->size_win_y) ?
				fdf->size_win_x : fdf->size_win_y);
		size_fil = ((fdf->col > fdf->row) ?
				fdf->col : fdf->row);
		fdf->d_plan = fdf->d_plan * size_fil / (12.0 * size_win / 900.0);
	}
	fdf->center = ft_vect_new(fdf->size_win_x / 2, fdf->size_win_y / 2, 0);
	fdf->unit0 = ft_vect_new(fdf->center->x, fdf->center->y, 0);
	fdf->plan0 = ft_vect_new(fdf->center->x, fdf->center->y, fdf->d_plan);
	fdf->user0 = ft_vect_new(fdf->center->x, fdf->center->y,
			fdf->d_plan + fdf->d_user);
	return (TRUE);
}
