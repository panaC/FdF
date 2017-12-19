/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:03:18 by pierre            #+#    #+#             */
/*   Updated: 2017/12/19 13:56:52 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

#include <stdlib.h>
#include <stdio.h>

int			expose_win(t_fdf *fdf)
{
	//draw to win here
	calc_3d_projection(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_grid(fdf);
}

int			mouse_win(int x, int y, t_fdf *fdf)
{
	static int		xx = 300;
	static int		yy = 200;

	if (x <= xx)
		printf("left\n");
	else
		printf("right\n");
	if (y <= yy)
		printf("up\n");
	else
		printf("down\n");
	xx = x;
	yy = y;
}

int			key_win(int key, t_fdf *fdf)
{
	if (key == K_ESCAPE)
		exit(0);
	else if (key == K_LEFT)
		calc_matrix_left(fdf);
	else if (key == K_RIGHT)
		calc_matrix_right(fdf);
	else if (key == K_UP)
		calc_matrix_up(fdf);
	else if (key == K_DOWN)
		calc_matrix_down(fdf);
	else if (key == 'k')
		trans_up(fdf);
	else if (key == 'j')
		trans_down(fdf);
	else if (key == 'h')
		trans_left(fdf);
	else if (key == 'l')
		trans_right(fdf);
	else if (key == 'a')
		trans_max(fdf);
	else if (key == 'z')
		trans_min(fdf);
	else if (key == 's')
		peak_up(fdf);
	else if (key == 'x')
		peak_down(fdf);

	return (TRUE);
}
