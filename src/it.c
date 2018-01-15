/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:03:18 by pierre            #+#    #+#             */
/*   Updated: 2018/01/15 16:17:37 by pleroux          ###   ########.fr       */
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
		mlx_destroy_window(fdf->mlx, fdf->win);
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
