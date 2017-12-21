/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:10:25 by pierre            #+#    #+#             */
/*   Updated: 2017/12/21 15:08:03 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

#include <stdio.h>

int			main(int ac, char **av)
{
	t_fdf		*fdf;

	if ((!(fdf = (t_fdf*)ft_memalloc(sizeof(*fdf)))))
		return (TRUE);
	if (!check_arg(fdf, ac, av))
		return (TRUE);
	if (!init_fdf(fdf))
		return (free_fdf(&fdf));
	if (!fill_vector(fdf))
		return (free_fdf(&fdf));
	if (!calc_matrix_init(fdf))
		return (free_fdf(&fdf));
	if (!init_mlx(fdf))
		return (free_fdf(&fdf));
	mlx_loop(fdf->mlx);
	return (!(free_fdf(&fdf)));
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

