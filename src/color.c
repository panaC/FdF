/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:00:22 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/04 14:29:36 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf.h"

int				get_color(t_fdf *fdf, char *str)
{
	char		**split;
	int			ret;
	int			i;

	i = 0;
	ret = fdf->color;
	split = ft_strsplit(str, ',');
	if (split && split[0] && split[1])
		ret = ft_atoi_hex(split[1]);
	while (split && split[i] != NULL)
		ft_memdel((void**)&(split[i]));
	ft_memdel((void**)&(split));
	return (ret);
}
