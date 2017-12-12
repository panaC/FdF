/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:41:51 by pierre            #+#    #+#             */
/*   Updated: 2017/12/12 17:07:29 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_H
# define _VECTOR_H

typedef struct					s_vect
{
	int							x;
	int							y;
	int							z;
	int							w;
}								t_vect;


t_vect				*vect_init(t_vect *v, int x, int y, int z);
t_vect				*vect_new(int x, int y, int z);
void				vect_copy(t_vect *dest, t_vect *src);
double				vect_norm(const t_vect *v);
t_vect*				vect_unit(t_vect *v);
int					vect_scalar_product(t_vect *v1, t_vect *v2);
t_vect				*vect_cross_product(t_vect *a, t_vect *b);
t_vect				*vect_add_vect(t_vect *a, t_vect *b);
t_vect				*vect_mul_vect(t_vect *a, t_vect *b);
t_vect				*vect_sub_vect(t_vect *a, t_vect *b);
t_vect				*vect_add_scalar(t_vect *a, int b);
t_vect				*vect_mul_scalar(t_vect *a, int b);
t_vect				*vect_sub_scalar(t_vect *a, int b);
void				print_vect(t_vect *v);

#endif
