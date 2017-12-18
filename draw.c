/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 09:54:09 by pierre            #+#    #+#             */
/*   Updated: 2017/12/16 17:59:01 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <stdlib.h>
#include "fdf.h"
#include "vector.h"

void		line(t_fdf *a, t_vect *s, t_vect *e, int color)
{
	int dx,dy,i,xinc,yinc,cumul,x,y ;
	x = s->x ;
	y = s->y ;
	dx = e->x - s->x ;
	dy = e->y - s->y ;
	xinc = ( dx > 0 ) ? 1 : -1 ;
	yinc = ( dy > 0 ) ? 1 : -1 ;
	dx = abs(dx) ;
	dy = abs(dy) ;
	mlx_pixel_put(a->mlx, a->win, x, y, COLOR);
	if ( dx > dy ) {
		cumul = dx / 2 ;
		for ( i = 1 ; i <= dx ; i++ ) {
			x += xinc ;
			cumul += dy ;
			if ( cumul >= dx ) {
				cumul -= dx ;
				y += yinc ; }
			mlx_pixel_put(a->mlx, a->win, x, y, color);
		} }
	else {
		cumul = dy / 2 ;
		for ( i = 1 ; i <= dy ; i++ ) {
			y += yinc ;
			cumul += dx ;
			if ( cumul >= dy ) {
				cumul -= dy ;
				x += xinc ; }
			mlx_pixel_put(a->mlx, a->win, x, y, color);
		} }
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

/*
 * A tester
 */
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
						fdf->grid[(j * fdf->col) + i + 1]->dot2, 0xFFFFFF);
			}
			if (j < (fdf->row - 1))
			{
				line(fdf, fdf->grid[(j * fdf->col) + i]->dot2,
						fdf->grid[((j + 1) * fdf->col) + i]->dot2, 0xFFFFFF);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (TRUE);
}
