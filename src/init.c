/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:38:39 by pierre            #+#    #+#             */
/*   Updated: 2017/12/21 01:12:54 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <mlx_int.h>
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
	(fdf->ev[4]).key = 'k';
	(fdf->ev[4]).ft = trans_up;
	(fdf->ev[5]).key = 'j';
	(fdf->ev[5]).ft = trans_down;
	(fdf->ev[6]).key = 'h';
	(fdf->ev[6]).ft = trans_left;
	(fdf->ev[7]).key = 'l';
	(fdf->ev[7]).ft = trans_right;
	(fdf->ev[8]).key = 'a';
	(fdf->ev[8]).ft = trans_max;
	(fdf->ev[9]).key = 'z';
	(fdf->ev[9]).ft = trans_min;
	(fdf->ev[10]).key = 's';
	(fdf->ev[10]).ft = peak_up;
	(fdf->ev[11]).key = 'x';
	(fdf->ev[11]).ft = peak_down;
	return (TRUE);
}

int			init_fdf(t_fdf *fdf)
{
	ft_setparam_int(fdf->arg, "coef-gap", &(fdf->coef_gap_vector), COEF_GAP);
	ft_setparam_int(fdf->arg, "coef-top", &(fdf->coef_top), COEF_PEAK);
	ft_setparam_int(fdf->arg, "d-plan", &(fdf->d_plan), D_PLAN);
	ft_setparam_int(fdf->arg, "d-user", &(fdf->d_user), D_USER);
	ft_setparam_hex(fdf->arg, "color", &(fdf->color), 0xFFFFFF);
	ft_setparam_doubleint(fdf->arg, "size-win", &(fdf->size_win_x), SIZE_X, 0);
	ft_setparam_doubleint(fdf->arg, "size-win", &(fdf->size_win_y), SIZE_Y, 1);
	fdf->title = ft_strnew(50);
	fdf->file = ft_strnew(fdf->arg->data_param->content_size + 1);
	fdf->file = (t_string)ft_memcpy(fdf->file,
			(t_string)fdf->arg->data_param->content,
			fdf->arg->data_param->content_size);
	ft_strlcat(fdf->title, "fdf -> ", 50);
	ft_strlcat(fdf->title, fdf->file, 50);
	fdf->grid = NULL;
	fdf->center = ft_vect_new(fdf->size_win_x / 2, fdf->size_win_y / 2, 0);
	fdf->unit0 = ft_vect_new(fdf->center->x, fdf->center->y, 0);
	fdf->plan0 = ft_vect_new(fdf->center->x, fdf->center->y, fdf->d_plan);
	fdf->user0 = ft_vect_new(fdf->center->x, fdf->center->y,
			fdf->d_plan + fdf->d_user);
	init_tab(fdf);
	return (TRUE);
}

int			init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (FALSE);
	fdf->win = mlx_new_window(fdf->mlx, fdf->size_win_x, fdf->size_win_y,
			fdf->title);
	/*
	 * mlx_hook(fdf->win, MotionNotify, PointerMotionMask, mouse_win, fdf);
	 */
	mlx_expose_hook(fdf->win, expose_win, fdf);
	mlx_key_hook(fdf->win, key_win, fdf);
	return (TRUE);
}

int			free_fdf(t_fdf **fdf)
{
	t_fdf	*fd;
	int		i;

	fd = *fdf;
	ft_freearg(&(fd->arg));
	ft_memdel((void**)&(fd->mlx));
	ft_memdel((void**)&(fd->center));
	ft_memdel((void**)&(fd->title));
	ft_memdel((void**)&(fd->file));
	i = 0;
	while (i < (fd->col * fd->row))
	{
		ft_memdel((void**)&(fd->grid[i]->dot3));
		ft_memdel((void**)&(fd->grid[i]->dot2));
		ft_memdel((void**)&(fd->grid[i]));
		i++;
	}
	ft_memdel((void**)&(fd->grid));
	ft_memdel((void**)&(fd->unit0));
	ft_memdel((void**)&(fd->plan0));
	ft_memdel((void**)&(fd->user0));
	ft_memdel((void**)fdf);
	return (TRUE);
}

t_dot		*dot_new(t_vect *s1, t_vect *s2, t_vect *pos, int color)
{
	t_dot	*dot;

	if ((!(dot = ft_memalloc(sizeof(*dot)))))
		return (NULL);
	dot->dot2	= s2;
	dot->dot3	= s1;
	dot->x		= pos->x;
	dot->y		= pos->y;
	dot->color	= color;
	ft_memdel((void**)&pos);
	return (dot);
}
