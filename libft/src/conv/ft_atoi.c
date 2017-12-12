/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:11:58 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 12:12:08 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_atoi(const char *nptr)
{
	int			i;
	int			ret;
	int			neg;

	ret = 0;
	i = 0;
	neg = 1;
	while (nptr[i] && ft_isspace((int)nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret *= 10;
		ret += (int)nptr[i] - '0';
		i++;
	}
	return (neg * ret);
}
