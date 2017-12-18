/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:37:07 by pierre            #+#    #+#             */
/*   Updated: 2017/12/18 17:44:26 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARG_H
# define _ARG_H

#include <libft.h>

typedef struct				s_arg
{
	t_string				short_param;
	t_list					*long_param;
	t_list					*data_param;
	t_bool					state;
}							t_arg;

t_arg			*get_arg(int ac, char **argv);
t_bool			get_short_param(t_arg *a, t_string s);

#endif
