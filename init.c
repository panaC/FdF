/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:38:39 by pierre            #+#    #+#             */
/*   Updated: 2017/12/19 17:15:19 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <mlx_int.h>
#include <libft.h>
#include "vector.h"
#include "fdf.h"
#include <stdio.h>

int			init_fdf(t_fdf *fdf)
{
	t_list	*tmp;

	ft_setparam_int(fdf->arg, "coef-gap", &(fdf->coef_gap_vector), COEF_GAP);
	printf("init\n");
	ft_setparam_int(fdf->arg, "coef-top", &(fdf->coef_top), COEF_PEAK);
	ft_setparam_int(fdf->arg, "d-plan", &(fdf->d_plan), D_PLAN);
	ft_setparam_int(fdf->arg, "d-user", &(fdf->d_user), D_USER);
	ft_setparam_hex(fdf->arg, "color", &(fdf->color), 0xFFFFFF);
	ft_setparam_doubleint(fdf->arg, "size-win", &(fdf->size_win_x), SIZE_X, 0);
	ft_setparam_doubleint(fdf->arg, "size-win", &(fdf->size_win_y), SIZE_Y, 1);
	fdf->title = ft_strnew(50);
	fdf->file = ft_strnew(fdf->arg->data_param->content_size + 1);
	fdf->file = (t_string)ft_memcpy(fdf->file, (t_string)fdf->arg->data_param->content, fdf->arg->data_param->content_size);
	ft_strlcat(fdf->title, "fdf -> ", 50);
	ft_strlcat(fdf->title, fdf->file, 50);
	fdf->grid = NULL;
	fdf->center = vect_new(fdf->size_win_x / 2, fdf->size_win_y / 2, 0);
	fdf->unit0 = vect_new(fdf->center->x, fdf->center->y, 0);
	fdf->plan0 = vect_new(fdf->center->x, fdf->center->y, fdf->d_plan);
	fdf->user0 = vect_new(fdf->center->x, fdf->center->y,
			fdf->d_plan + fdf->d_user);
	return (TRUE);
}

int			init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		printf("error\n");
	fdf->win = mlx_new_window(fdf->mlx, fdf->size_win_x, fdf->size_win_y,
			fdf->title);
	//mlx_hook(fdf->win, MotionNotify, PointerMotionMask, mouse_win, fdf);
	mlx_expose_hook(fdf->win, expose_win, fdf);
	mlx_key_hook(fdf->win, key_win, fdf);
	return (TRUE);
}

int			free_fdf(t_fdf *fdf)
{
	ft_memdel((void**)&(fdf->title));
	ft_memdel((void**)&(fdf->file));
	ft_memdel((void**)&(fdf->grid));
	ft_memdel((void**)&(fdf->unit0));
	ft_memdel((void**)&(fdf->plan0));
	ft_memdel((void**)&(fdf->user0));
	return (TRUE);
}

t_dot		*dot_new(t_vect *s1, t_vect *s2, t_vect *pos, int color)
{
	t_dot		*dot;

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
