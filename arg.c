/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:43:55 by pierre            #+#    #+#             */
/*   Updated: 2017/12/19 14:22:15 by pierre           ###   ########.fr       */
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
	ft_putstr(" [option] maps\n");
	return (FALSE);
}

t_bool				check_arg(t_fdf *fdf, int ac, char **av)
{
	if ((!(fdf->arg = ft_get_arg(ac, av))))
		return (FALSE);
	if (!fdf->arg->state || ft_lstlen(fdf->arg->data_param) != 1)
		return (error_arg(av[0]));
	return (TRUE);
}
