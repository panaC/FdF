/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:41:51 by pierre            #+#    #+#             */
/*   Updated: 2017/12/16 14:02:52 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MARIX_H
# define _MARIX_H

#include "vector.h"

/*
 * | xx xy xz wx |
 * | yx yy yz wy |
 * | zx zy zz wz |
 * | tx ty tz ww |
 */

typedef struct				s_matrix
{
	double					xx;
	double					xy;
	double					xz;
	double					yx;
	double					yy;
	double					yz;
	double					zx;
	double					zy;
	double					zz;
	double					tx;
	double					ty;
	double					tz;
	double					wx;
	double					wy;
	double					wz;
	double					ww;
}							t_matrix;

t_matrix			*matrix_new();
t_matrix			*matrix_identity(t_matrix *m);
t_vect				*matrix_mul_vect(t_vect *v, t_matrix *m);
void				matrix_print(t_matrix *m);

#endif
