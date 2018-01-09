/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 09:54:09 by pierre            #+#    #+#             */
/*   Updated: 2018/01/09 12:05:13 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <stdlib.h>
#include "fdf.h"
#include "vector.h"

static void	line1(t_fdf *fdf, t_vect *s, int *d, t_uint32 *c)
{
	int		cumul;
	int		i;
	int		inc[2];
	int		cor[2];

	cor[0] = s->x;
	cor[1] = s->y;
	inc[0] = (d[0] > 0) ? 1 : -1;
	inc[1] = (d[1] > 0) ? 1 : -1;
	d[0] = ft_abs(d[0]);
	d[1] = ft_abs(d[1]);
	cumul = d[0] / 2;
	i = 1;
	while (i <= d[0])
	{
		cor[0] += inc[0];
		cumul += d[1];
		if (cumul >= d[0])
		{
			cumul -= d[0];
			cor[1] += inc[1];
		}
		mlx_pixel_put(fdf->mlx, fdf->win, cor[0], cor[1], col_deg(c, i));
		++i;
	}
}

static void	line2(t_fdf *fdf, t_vect *s, int *d, t_uint32 *c)
{
	int		cumul;
	int		i;
	int		inc[2];
	int		cor[2];

	cor[0] = s->x;
	cor[1] = s->y;
	inc[0] = (d[0] > 0) ? 1 : -1;
	inc[1] = (d[1] > 0) ? 1 : -1;
	d[0] = ft_abs(d[0]);
	d[1] = ft_abs(d[1]);
	cumul = d[1] / 2;
	i = 1;
	while (i <= d[1])
	{
		cor[1] += inc[1];
		cumul += d[0];
		if (cumul >= d[1])
		{
			cumul -= d[1];
			cor[0] += inc[0];
		}
		mlx_pixel_put(fdf->mlx, fdf->win, cor[0], cor[1], col_deg(c, i));
		++i;
	}
}

void		line(t_fdf *fdf, t_dot *s, t_dot *e)
{
	int			d[2];
	t_uint32	*color_tab;

	d[0] = e->dot2->x - s->dot2->x;
	d[1] = e->dot2->y - s->dot2->y;
	mlx_pixel_put(fdf->mlx, fdf->win, s->dot2->x, s->dot2->y, s->color);
	if (ft_abs(d[0]) > ft_abs(d[1]))
	{
		color_tab = set_tab_col_deg(s->color, e->color, d[0]);
		line1(fdf, s->dot2, d, color_tab);
	}
	else
	{
		color_tab = set_tab_col_deg(s->color, e->color, d[1]);
		line2(fdf, s->dot2, d, color_tab);
	}
	ft_memdel((void**)&(color_tab));
}

/*
** int			draw_line(t_fdf *a, t_vect *s1, t_vect *s2, int color)
** {
**	t_vect p1;
**	t_vect p2;
**
**	p1.x = a->center->x - s1->x;
**	p1.y = a->center->y - s1->y;
**	p2.x = a->center->x + s2->x;
**	p2.y = a->center->y - s2->y;
**	line(a, &p1, &p2, color);
**	//ft_memdel((void**)&s1);
**	//ft_memdel((void**)&s2);
**	return (TRUE);
** }
*/

int			draw_grid(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < fdf->row)
	{
		while (i < fdf->col)
		{
			if (i < (fdf->col - 1))
			{
				line(fdf, fdf->grid[(j * fdf->col) + i],
						fdf->grid[(j * fdf->col) + i + 1]);
			}
			if (j < (fdf->row - 1))
			{
				line(fdf, fdf->grid[(j * fdf->col) + i],
						fdf->grid[((j + 1) * fdf->col) + i]);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (TRUE);
}
