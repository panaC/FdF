/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 09:54:09 by pierre            #+#    #+#             */
/*   Updated: 2017/12/20 17:45:57 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <stdlib.h>
#include "fdf.h"
#include "vector.h"

static void	line1(t_fdf *fdf, t_vect *s, int dx, int dy, int color)
{
	int		cumul;
	int		i;
	int		inc[2];
	int		cor[2];
	
	cor[0] = s->x;
	cor[1] = s->y;
	inc[0] = ( dx > 0 ) ? 1 : -1;
	inc[1] = ( dy > 0 ) ? 1 : -1;
	dx = ft_abs(dx);
	dy = ft_abs(dy);
	cumul = dx / 2;
	i = 1;
	while (i <= dx)
	{
		cor[0] += inc[0];
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			cor[1] += inc[1];
		}
		mlx_pixel_put(fdf->mlx, fdf->win, cor[0], cor[1], color);
		++i;
	}
}

static void	line2(t_fdf *fdf, t_vect *s, int dx, int dy, int color)
{
	int		cumul;
	int		i;
	int		inc[2];
	int		cor[2];
	
	cor[0] = s->x;
	cor[1] = s->y;
	inc[0] = ( dx > 0 ) ? 1 : -1;
	inc[1] = ( dy > 0 ) ? 1 : -1;
	dx = ft_abs(dx);
	dy = ft_abs(dy);
	cumul = dy / 2;
	i = 1;
	while (i <= dy)
	{
		cor[1] += inc[1];
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			cor[0] += inc[0];
		}
		mlx_pixel_put(fdf->mlx, fdf->win, cor[0], cor[1], color);
		++i;
	}
}

void		line(t_fdf *fdf, t_vect *s, t_vect *e, int color)
{
	int		dx;
	int		dy;

	dx = e->x - s->x;
	dy = e->y - s->y;
	mlx_pixel_put(fdf->mlx, fdf->win, s->x, s->y, color);
	if (ft_abs(dx) > ft_abs(dy))
		line1(fdf, s, dx, dy, color);
	else
		line2(fdf, s, dx, dy, color);
}


int			draw_line(t_fdf *a, t_vect *s1, t_vect *s2, int color)
{
	t_vect p1;
	t_vect p2;

	p1.x = a->center->x - s1->x;
	p1.y = a->center->y - s1->y;
	p2.x = a->center->x + s2->x;
	p2.y = a->center->y - s2->y;
	line(a, &p1, &p2, color);
	//ft_memdel((void**)&s1);
	//ft_memdel((void**)&s2);
}

int			draw_grid(t_fdf *fdf)
{
	int		i;
	int		j;

	i = j = 0;
	while (j < fdf->row)
	{
		while (i < fdf->col)
		{
			if (i < (fdf->col - 1))
			{
				line(fdf, fdf->grid[(j * fdf->col) + i]->dot2,
						fdf->grid[(j * fdf->col) + i + 1]->dot2, fdf->color);
			}
			if (j < (fdf->row - 1))
			{
				line(fdf, fdf->grid[(j * fdf->col) + i]->dot2,
						fdf->grid[((j + 1) * fdf->col) + i]->dot2, fdf->color);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (TRUE);
}
