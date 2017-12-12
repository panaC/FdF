/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:15:18 by pierre            #+#    #+#             */
/*   Updated: 2017/12/12 10:28:55 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

#include "vector.h"

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	t_vect				*center;
}						t_fdf;



#endif
