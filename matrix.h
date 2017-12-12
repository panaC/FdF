/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:41:51 by pierre            #+#    #+#             */
/*   Updated: 2017/12/11 19:16:04 by pierre           ###   ########.fr       */
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
	int			xx;
	int			xy;
	int			xz;
	int			yx;
	int			yy;
	int			yz;
	int			zx;
	int			zy;
	int			zz;
	int			tx;
	int			ty;
	int			tz;
	int			wx;
	int			wy;
	int			wz;
	int			ww;
}							t_matrix;

t_matrix			*matrix_new();
t_matrix			*matrix_identity(t_matrix *m);
t_vect				*matrix_mul_vect(t_vect *v, t_matrix *m);
void				matrix_print(t_matrix *m);

#endif
