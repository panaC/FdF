/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:03:18 by pierre            #+#    #+#             */
/*   Updated: 2017/12/16 15:19:32 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

int			expose_win(t_fdf *fdf)
{
	//draw to win here
	calc_3d_projection(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_grid(fdf);
	//line(fdf, vect_new(260, 180, 20), vect_new(280, 180, 40), 0xFFFFFF);
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
	return (TRUE);
}
