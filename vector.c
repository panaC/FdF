/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:40:57 by pierre            #+#    #+#             */
/*   Updated: 2017/12/12 17:09:10 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <libft.h>
#include "vector.h"

t_vect				*vect_init(t_vect *v, int x, int y, int z)
{
	v->x = x;
	v->y = y;
	v->z = z;
	v->w = 1;
	return (v);
}

t_vect				*vect_new(int x, int y, int z)
{
	t_vect			*ret;

	if ((!(ret = (t_vect*)ft_memalloc(sizeof(ret)))))
		return (NULL);
	return(vect_init(ret, x, y, z));
}

void				vect_copy(t_vect *dest, t_vect *src)
{
	dest->x = src->x;
	dest->y = src->y;
	dest->z = src->z;
}

double				vect_norm(const t_vect *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

/*
 * Ne marche pas si x y z = int
 * mais par contre double oui
 */
t_vect*				vect_unit(t_vect *v)
{
	double	norm;

	norm = vect_norm(v);
	if (norm > 0)
	{
		norm = 1 / norm;
		v->x *= norm;
		v->y *= norm;
		v->z *= norm;
	}
	return (v);
}

int					vect_scalar_product(t_vect *v1, t_vect *v2)
{
	return(v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vect				*vect_cross_product(t_vect *a, t_vect *b)
{
	t_vect			*ret;

	if ((!(ret = (t_vect*)ft_memalloc(sizeof(ret)))))
		return (NULL);
	ret->x = a->y * b->z - a->z * b->y;
	ret->y = a->z * b->x - a->x * b->z;
	ret->z = a->x * b->y - a->y * b->x;
	ret->w = 1;
	return(ret);
}

t_vect				*vect_add_vect(t_vect *a, t_vect *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
}

t_vect				*vect_mul_vect(t_vect *a, t_vect *b)
{
	a->x *= b->x;
	a->y *= b->y;
	a->z *= b->z;
}

t_vect				*vect_sub_vect(t_vect *a, t_vect *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
}

t_vect				*vect_add_scalar(t_vect *a, int b)
{
	a->x += b;
	a->y += b;
	a->z += b;
}

t_vect				*vect_mul_scalar(t_vect *a, int b)
{
	a->x *= b;
	a->y *= b;
	a->z *= b;
}

t_vect				*vect_sub_scalar(t_vect *a, int b)
{
	a->x -= b;
	a->y -= b;
	a->z -= b;
}

void				print_vect(t_vect *v)
{
	ft_putstr("x=");
	ft_putnbr(v->x);
	ft_putstr("y=");
	ft_putnbr(v->y);
	ft_putstr("z=");
	ft_putnbr(v->z);
	ft_putstr("\n");
}
