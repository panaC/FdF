/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:43:55 by pierre            #+#    #+#             */
/*   Updated: 2018/01/11 13:27:39 by pleroux          ###   ########.fr       */
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
	ft_putstr(" OPTIONS :        \n"
			" --coef-gap=NUM\t\tGap between 2 dot\n"
			" --coef-top=NUM\t\tCoef for z axes\n"
			" --d-plan=NUM\t\tDistance between the plan and the center\n"
			" --d-user=NUM\t\tDistance between the user eye and the plan\n"
			" --color=NUM\t\tColor in Hex, Default is white\n"
			" --size-win=NUM,NUM\tWindow size by x,y\n"
			" --no-color\t\tDisable color\n"
			" --no-auto\t\tDisable auto scale\n"
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

static t_list		*set_arg(void)
{
	t_list			*lst;

	ft_lstaddstr(&lst, "coef-gap");
	ft_lstaddstr(&lst, "coef-top");
	ft_lstaddstr(&lst, "d-plan");
	ft_lstaddstr(&lst, "d-user");
	ft_lstaddstr(&lst, "color");
	ft_lstaddstr(&lst, "size-win");
	ft_lstaddstr(&lst, "no-color");
	ft_lstaddstr(&lst, "no-auto");
	ft_lstaddstr(&lst, "help");
	return (lst);
}

t_bool				check_arg(t_fdf *fdf, int ac, char **av)
{
	if ((!(fdf->arg = ft_get_arg(ac, av))))
		return (FALSE);
	if (!fdf->arg->state || ft_lstlen(fdf->arg->data_param) != 1 ||
			!ft_check_longparam(fdf->arg->long_param, set_arg(), TRUE))
		return (error_arg(av[0]));
	if (ft_search_param(fdf->arg->long_param, NULL, "help"))
		return (error_arg(av[0]));
	return (TRUE);
}
