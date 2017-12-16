/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:10:25 by pierre            #+#    #+#             */
/*   Updated: 2017/12/16 15:37:24 by pierre           ###   ########.fr       */
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


/*
 * 1 check param
 * 2 fill vector
 * 3 init fdf
 * 4 draw
 * 5 loop -> control -> draw -> loop
 */

int			main(int ac, char **av)
{
	t_fdf		*fdf;
	int i = 0;

	/*check file*/
	if (ac != 2)
		return (FALSE);

	if ((!(fdf = (t_fdf*)ft_memalloc(sizeof(*fdf)))))
		return (FALSE);
	init_fdf(fdf, av[1]);
	printf("ret %d\n", fill_vector(fdf));
/*	while (fdf->grid[i] != NULL) {
		print_vect((fdf->grid[i])->dot3);
		i++;
	}
	ft_putstr("center :");
	print_vect(fdf->center);*/
	calc_matrix_init(fdf);
/*	i = 0;
	while (fdf->grid[i] != NULL) {
		print_vect((fdf->grid[i])->dot3);
		i++;
	}
	i = 0;
	while (fdf->grid[i] != NULL) {
		print_vect((fdf->grid[i])->dot2);
		i++;
	}*/
	printf("aa\n");
	init_mlx(fdf);
	printf("bb\n");
	mlx_loop(fdf->mlx);
	printf("cc\n");
	ft_memdel((void**)&fdf);

	return (0);
}
