/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:30:06 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/15 14:01:18 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf.h"

int			free_fdf(t_fdf **fdf)
{
	t_fdf	*fd;
	int		i;

	fd = *fdf;
	ft_freearg(&(fd->arg));
	ft_memdel((void**)&(fd->mlx));
	ft_memdel((void**)&(fd->center));
	ft_memdel((void**)&(fd->title));
	ft_memdel((void**)&(fd->file));
	i = 0;
	while (i < (fd->col * fd->row))
	{
		ft_memdel((void**)&(fd->grid[i]->dot3));
		ft_memdel((void**)&(fd->grid[i]->dot2));
		ft_memdel((void**)&(fd->grid[i]));
		i++;
	}
	ft_memdel((void**)&(fd->grid));
	ft_memdel((void**)&(fd->unit0));
	ft_memdel((void**)&(fd->plan0));
	ft_memdel((void**)&(fd->user0));
	ft_memdel((void**)fdf);
	return (TRUE);
}

t_dot		*dot_new(t_vect *s1, t_vect *s2, t_vect *pos, t_uint32 color)
{
	t_dot	*dot;

	if ((!(dot = ft_memalloc(sizeof(*dot)))))
		return (NULL);
	dot->dot2 = s2;
	dot->dot3 = s1;
	dot->x = pos->x;
	dot->y = pos->y;
	dot->color = color;
	ft_memdel((void**)&pos);
	return (dot);
}
