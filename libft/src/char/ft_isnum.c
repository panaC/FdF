/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:10:33 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/10 20:55:01 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isnum(int c)
{
	if (c >= 48 && c < 57)
		return (1);
	return (0);
}
