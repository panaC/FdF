/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:10:25 by pierre            #+#    #+#             */
/*   Updated: 2018/01/09 18:20:26 by pleroux          ###   ########.fr       */
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
	printf("OK\n");
	if (!init_fdf(fdf))
		return (free_fdf(&fdf));
	printf("OK\n");
	if (!fill_vector(fdf))
		return (free_fdf(&fdf));
	printf("OK\n");
	if (!calc_matrix_init(fdf))
		return (free_fdf(&fdf));
	printf("OK\n");
	if (!init_mlx(fdf))
		return (free_fdf(&fdf));
	printf("OK2 %d %d\n", fdf->size_win_x, fdf->size_win_y);
	mlx_loop(fdf->mlx);
	return (!(free_fdf(&fdf)));
}
