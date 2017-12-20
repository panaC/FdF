/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:03:18 by pierre            #+#    #+#             */
/*   Updated: 2017/12/20 19:30:06 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

#include <stdlib.h>
#include <stdio.h>

int			expose_win(t_fdf *fdf)
{
	calc_3d_projection(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_grid(fdf);
	return (TRUE);
}

int			key_win(int key, t_fdf *fdf)
{
	int		i;

	i = 0;
	if (key == K_ESCAPE)
	{
		free_fdf(&fdf);
		exit(0);
	}
	while (i < 12)
	{
		if ((fdf->ev[i]).key == key)
			(fdf->ev[i]).ft(fdf);
		i++;
	}
	return (TRUE);
}

/*int			mouse_win(int x, int y, t_fdf *fdf)
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
}*/
