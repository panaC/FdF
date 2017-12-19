/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:10:25 by pierre            #+#    #+#             */
/*   Updated: 2017/12/19 17:09:13 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <mlx_int.h>
#include <libft.h>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"
#include "fdf.h"

#include <stdio.h>

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

	if ((!(fdf = (t_fdf*)ft_memalloc(sizeof(*fdf)))))
		return (FALSE);
	if (!check_arg(fdf, ac, av))
		return (FALSE);
	init_fdf(fdf);
	printf("ret %d\n", fill_vector(fdf));
	calc_matrix_init(fdf);
	init_mlx(fdf);
	mlx_loop(fdf->mlx);
	ft_memdel((void**)&fdf);
	return (0);
}

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
/*	while (fdf->grid[i] != NULL) {
		print_vect((fdf->grid[i])->dot3);
		i++;
	}
	ft_putstr("center :");
	print_vect(fdf->center);*/

