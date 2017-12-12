/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 09:57:26 by pierre            #+#    #+#             */
/*   Updated: 2017/12/12 10:26:01 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DRAW_H
# define _DRAW_H

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

void		line(t_fdf *a, t_point *s, t_point *e, int color);
int			draw_line(t_fdf *a, t_point *s1, t_point *s2, int color);
t_point		*vect_to_point(t_vect *v);

#endif
