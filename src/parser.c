/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:15:10 by pierre            #+#    #+#             */
/*   Updated: 2017/12/21 16:58:02 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <vector.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <unistd.h>
#include <get_next_line.h>
#include <stdlib.h>
#include "fdf.h"

int			check_dim_grid(t_fdf *a)
{
	int			fd;
	char		*line;
	int			col;
	int			row;

	row = 1;
	if (((fd = open(a->file, O_RDONLY)) < 0))
		return (FALSE);
	if (!get_next_line(fd, &line))
		return (FALSE);
	col = ft_nb_split(line, ' ');
	ft_memdel((void**)&(line));
	while (get_next_line(fd, &line))
	{
		if (col != ft_nb_split(line, ' '))
			return (FALSE);
		ft_memdel((void**)&(line));
		row++;
	}
	a->row = row;
	a->col = col;
	lseek(fd, 0, SEEK_SET);
	close(fd);
	ft_memdel((void**)&(line));
	return ((row == 0 || col == 0) ? FALSE : TRUE);
}


int			fill_grid_vector(t_fdf *a, int fd)
{
	int			x;
	int			y;
	char		*line;
	char		**line_row;

	while (get_next_line(fd, &line))
	{
		x = 0;
		line_row = ft_strsplit(line, ' ');
		while (line_row[x] != NULL)
		{
			set_vector(a, x, y, ft_atoi(line_row[x]));
			ft_memdel((void**)&(line_row[x]));
			x++;
		}
		free(line_row);
		ft_memdel((void**)&(line));
		y++;
	}
	ft_memdel((void**)&(line));
	return (TRUE);
}

int			set_vector(t_fdf *a, int x, int y, int z)
{
	t_dot		*dot;

	dot = dot_new(ft_vect_new(x, y, z), ft_vect_new(0, 0, 0),
			ft_vect_new(x, y, 0), a->color + z * a->coef_top * 100);
	a->grid[(y * a->col) + x] = dot;
	return (TRUE);
}

int			fill_vector(t_fdf *a)
{
	int				fd;

	if (!ft_strlen(a->file))
		return (FALSE);
	if (!check_dim_grid(a))
		return (FALSE);
	if ((!(a->grid = (t_dot**)ft_memalloc(
						sizeof(*a->grid) * a->row * a->col + 1))))
		return (FALSE);
	if (((fd = open(a->file, O_RDONLY)) < 0))
		return (FALSE);
	sleep(0.01);
	if (!fill_grid_vector(a, fd))
		return (FALSE);
	close(fd);
	return (TRUE);
}
