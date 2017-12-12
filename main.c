/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:10:25 by pierre            #+#    #+#             */
/*   Updated: 2017/12/12 17:59:37 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <mlx_int.h>
#include <stdio.h>
#include <libft.h>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"
#include "fdf.h"
#include "draw.h"

#define		SIZE_X	600
#define		SIZE_Y	400


int			mouse_win(int x, int y, void *p)
{
//	printf("%d, %d\n", x, y);
	//mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
	//line(mlx, win, 0, 0, x ,y, 0xFF00);
}

int			expose(t_fdf *p)
{
	t_vect		*ref;

	/*p->center = vect_new(300, 200, 0);
	ref = vect_new(0, 0, 0);

	t_vect *s = vect_new(0,0,0);
	t_vect *e = vect_new(100,100,0);

	draw_line(p, vect_to_point(s), vect_to_point(e), 0xFFFFFF);

	e->x = 300;
	e->y = 200;
	draw_line(p, vect_to_point(s), vect_to_point(e), 0xFFFFFF);

	e->x = -300;
	e->y = 200;
	draw_line(p, vect_to_point(s), vect_to_point(e), 0xFFFFFF);

	e->x = 300;
	e->y = -200;
	draw_line(p, vect_to_point(s), vect_to_point(e), 0xFFFFFF);

	e->x = -300;
	e->y = -200;
	draw_line(p, vect_to_point(s), vect_to_point(e), 0xFFFFFF);*/



}

int			main(int ac, char **av)
{
	t_fdf		fdf;

	/*check file*/
	if (ac != 2)
		return (FALSE);
	/* gap entre deux vector point afficher a l'ecran*/
	fdf.coef_gap_vector = 20;
	fdf.coef_top = 20;

	printf("ret %d\n", fill_vector(&fdf, av[1]));
	int i = 0;
	while (fdf.grid[i] != NULL) {
		print_vect(fdf.grid[i]);
		i++;
	}
	ft_putstr("center :");
	print_vect(fdf.center);

	fdf.mlx = mlx_init();
	if (!fdf.mlx)
		printf("error\n");
	fdf.win = mlx_new_window(fdf.mlx, SIZE_X, SIZE_Y, "Hello world");

	mlx_hook(fdf.win, MotionNotify, PointerMotionMask, mouse_win, &fdf);
	mlx_expose_hook(fdf.win, expose, &fdf);

	mlx_loop(fdf.mlx);

	return (0);
}
