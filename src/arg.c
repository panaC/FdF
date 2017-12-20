/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:43:55 by pierre            #+#    #+#             */
/*   Updated: 2017/12/20 18:18:20 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arg.h>
#include <libft.h>
#include "fdf.h"

#include <stdio.h>

static t_bool		error_arg(t_string s)
{
	ft_putstr("Usage ");
	ft_putstr(s);
	ft_putstr(" [option] map\n\n");
	ft_putstr("Draw a map in 3D view by wireframe design\n"
			"A map contain only the dot top for each coordinate\n\n");
	ft_putstr(" OPTION :        \n"
			" --coef-gap=NUM\t\tGap between 2 dot\n"
			" --coef-top=NUM\t\tCoef for z axes\n"
			" --d-plan=NUM\t\tDistance between the plan and the center\n"
			" --d-user=NUM\t\tDistance between the user eye and the plan\n"
			" --color=NUM\t\tColor in Hex, Default is white\n"
			" --size-win=NUM,NUM\tWindow size by x,y\n"
			" --help\t\t\tThis help\n\n"
			" CONTROLS :\n"
			" LEFT - RIGHT - UP - DOWN :\n"
			"\t3D view by rotation of 10Deg per each key press\n"
			" h - j - k - l :\n"
			"\tTranslation on x and y\n"
			" a - z :\n"
			"\tZoom max - min on 3D view\n"
			" s - x :\n"
			"\tZoom z axes\n");
	return (FALSE);
}

t_bool				check_arg(t_fdf *fdf, int ac, char **av)
{
	if ((!(fdf->arg = ft_get_arg(ac, av))))
		return (FALSE);
	if (!fdf->arg->state || ft_lstlen(fdf->arg->data_param) != 1)
		return (error_arg(av[0]));
	if (ft_lststrfind(fdf->arg->long_param, NULL, "help"))
	{
		error_arg(av[0]);
		return (FALSE);
	}
	return (TRUE);
}
