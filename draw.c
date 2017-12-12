/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 09:54:09 by pierre            #+#    #+#             */
/*   Updated: 2017/12/12 10:37:46 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <stdlib.h>
#include "fdf.h"
#include "vector.h"
#include "draw.h"

void		line(t_fdf *a, t_point *s, t_point *e, int color)
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
	mlx_pixel_put(a->mlx, a->win, x, y, color);
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

int			draw_line(t_fdf *a, t_point *s1, t_point *s2, int color)
{
	t_point p1;
	t_point p2;

	p1.x = a->center->x - s1->x;
	p1.y = a->center->y - s1->y;
	p2.x = a->center->x + s2->x;
	p2.y = a->center->y - s2->y;
	line(a, &p1, &p2, color);
	ft_memdel((void**)&s1);
	ft_memdel((void**)&s2);
}

t_point		*vect_to_point(t_vect *v)
{
	t_point	*ret;

	if ((!(ret = ft_memalloc(sizeof(v)))))
		return (NULL);
	ret->x = v->x;
	ret->y = v->y;
	return (ret);
}
