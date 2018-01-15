/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:10:25 by pierre            #+#    #+#             */
/*   Updated: 2018/01/15 16:17:42 by pleroux          ###   ########.fr       */
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
	if (!init_auto(fdf))
		return (free_fdf(&fdf));
	if (!calc_matrix_init(fdf))
		return (free_fdf(&fdf));
	if (!init_mlx(fdf))
		return (free_fdf(&fdf));
	mlx_loop(fdf->mlx);
	return (!(free_fdf(&fdf)));
}
