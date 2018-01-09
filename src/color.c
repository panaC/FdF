/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:00:22 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/09 10:43:59 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf.h"

t_uint32		get_color(t_fdf *fdf, char *str)
{
	char		**split;
	t_uint32	ret;
	int			i;

	i = 0;
	ret = fdf->color;
	split = ft_strsplit(str, ',');
	if (split && split[0] && split[1])
		ret = ft_atoi_hex(split[1]);
	while (split && split[i] != NULL)
		ft_memdel((void**)&(split[i]));
	ft_memdel((void**)&(split));
	return (ret);
}

t_uint32		*set_tab_col_deg(t_uint32 sc, t_uint32 ec, int d)
{
	t_uint32	*ret;

	if (!((ret = (t_uint32*)ft_memalloc(sizeof(t_uint32) * 5))))
		return (NULL);
	ret[0] = (t_uint32)sc;
	ret[1] = (t_uint32)ec;
	ret[2] = (ft_abs((sc & 0xFF - ec & 0xFF))
			/ ft_abs((d ? d : 1)));
	ret[3] = (ft_abs((((sc >> 8) & 0xFF) - ((ec >> 8) & 0xFF)))
			/ ft_abs((d ? d : 1)));
	ret[4] = (ft_abs((((sc >> 16) & 0xFF) - ((ec >> 16) & 0xFF)))
			/ ft_abs((d ? d : 1)));
	return (ret);
}

t_uint32		col_deg(t_uint32 *tab, int i)
{
	t_uint32	ret;
	t_uint32	tmp;

	tmp = tab[0] & 0xFF;
	tmp = (tmp > (tab[1] & 0xFF)) ?
		(tmp - i * tab[2]) : (tmp + i * tab[2]);
	ret = tmp;
	tmp = (tab[0] >> 8) & 0xFF;
	tmp = ((tmp > ((tab[1] >> 8) & 0xFF)) ?
			(tmp - i * tab[3]) : (tmp + i * tab[3]));
	tmp <<= 8;
	ret = ret | tmp;
	tmp = (tab[0] >> 16) & 0xFF;
	tmp = ((tmp > ((tab[1] >> 16) & 0xFF)) ?
			(tmp - i * tab[4]) : (tmp + i * tab[4]));
	tmp <<= 16;
	ret = ret | tmp;
	return (ret);
}
