/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:40:57 by pierre            #+#    #+#             */
/*   Updated: 2017/12/11 19:18:35 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "matrix.h"
#include <libft.h>

t_matrix			*matrix_new()
{
	t_matrix		*ret;

	if ((!(ret = (t_matrix*)ft_memalloc(sizeof(ret)))))
		return (NULL);
	return (matrix_identity(ret));
}

t_matrix			*matrix_identity(t_matrix *m)
{
	m->xx = 1;
	m->xy = 0;
	m->xz = 0;
	m->wx = 0;
	m->yx = 0;
	m->yy = 1;
	m->yz = 0;
	m->wy = 0;
	m->zx = 0;
	m->zy = 0;
	m->zz = 1;
	m->wz = 0;
	m->tx = 0;
	m->ty = 0;
	m->tz = 0;
	m->ww = 1;
	return (m);
}

t_vect			*matrix_mul_vect(t_vect *v, t_matrix *m)
{
	t_vect		*ret;

	ret = vect_new(0, 0, 0);
	ret->x = v->x * m->xx + v->y * m->yx + v->z * m->zx + m->tx;
	ret->y = v->x * m->xy + v->y * m->yy + v->z * m->zy + m->ty;
	ret->z = v->x * m->xz + v->y * m->yz + v->z * m->zz + m->tz;
	ret->w = v->x * m->wx + v->y * m->wy + v->z * m->wz + m->ww;
	if (ret->w != 1 && ret->w != 0)
	{
		ret->x /= ret->w;
		ret->y /= ret->w;
		ret->z /= ret->w;
	}
}

void			matrix_print(t_matrix *m)
{
	ft_putstr("| ");
	ft_putnbr(m->xx);
	ft_putchar(' ');
	ft_putnbr(m->xy);
	ft_putchar(' ');
	ft_putnbr(m->xz);
	ft_putchar(' ');
	ft_putnbr(m->wx);
	ft_putstr(" |\n");
	ft_putstr("| ");
	ft_putnbr(m->yx);
	ft_putchar(' ');
	ft_putnbr(m->yy);
	ft_putchar(' ');
	ft_putnbr(m->yz);
	ft_putchar(' ');
	ft_putnbr(m->wy);
	ft_putstr(" |\n");
	ft_putstr("| ");
	ft_putnbr(m->zx);
	ft_putchar(' ');
	ft_putnbr(m->zy);
	ft_putchar(' ');
	ft_putnbr(m->zz);
	ft_putchar(' ');
	ft_putnbr(m->wz);
	ft_putstr(" |\n");
	ft_putstr("| ");
	ft_putnbr(m->tx);
	ft_putchar(' ');
	ft_putnbr(m->ty);
	ft_putchar(' ');
	ft_putnbr(m->tz);
	ft_putchar(' ');
	ft_putnbr(m->ww);
	ft_putstr(" |\n");
}
