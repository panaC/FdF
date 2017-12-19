/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:15:10 by pierre            #+#    #+#             */
/*   Updated: 2017/12/19 17:18:08 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"
#include "vector.h"
#include <fcntl.h>
#include <sys/types.h> 
#include <unistd.h>
#include <get_next_line.h>
#include <stdio.h>

/*
 * taille de la grille et check regularite grille
 * retourne fdf avec la taille de la grille l et h
 *
 */
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
	while (get_next_line(fd, &line))
	{
		if (col != ft_nb_split(line, ' '))
			return (FALSE);
		row++;
	}
	a->row = row;
	a->col = col;
	lseek(fd, 0, SEEK_SET);
	close(fd);
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
//		printf("y %d\n", y);
		x = 0;
		line_row = ft_strsplit(line, ' ');
		while (line_row[x] != NULL)
		{
//			printf("x %d str %s\n", x, line_row[x]);
			set_vector(a, x, y, ft_atoi(line_row[x]));
			x++;
		}
		y++;
	}
	return (TRUE);
}

int			set_vector(t_fdf *a, int x, int y, int z)
{
	t_dot		*dot;

	dot = dot_new(vect_new(x, y, z), vect_new(0, 0, 0), vect_new(x, y, 0), COLOR);
	a->grid[(y * a->col) + x] = dot;
//	print_vect(a->grid[(y * a->col) + x]->dot3);
	return (TRUE);
}
//	printf("set vector : a->row %d [%d]\n", a->row, (y * a->col) + x);

/* 1 creation tab vect
 * 2 copie de tout les vecteur dans le tab
 * 3 analyse du fichier et copie dans tab
 */
int			fill_vector(t_fdf *a)
{
	t_vect			ptr;
	int				fd;

	if (!ft_strlen(a->file))
		return (FALSE);
//	printf("a\n");
	if (!check_dim_grid(a))
		return (FALSE);
//	printf("b\n");
	if ((!(a->grid = (t_dot**)ft_memalloc(
						sizeof(*a->grid) * a->row * a->col + 1))))
		return (FALSE);
//	printf("c\n");
	if (((fd = open(a->file, O_RDONLY)) < 0))
		return (FALSE);
	sleep(0.01);
	if (!fill_grid_vector(a, fd))
		return (FALSE);
	close(fd);
	return (TRUE);
}
