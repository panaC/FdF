/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:30:27 by pierre            #+#    #+#             */
/*   Updated: 2017/12/18 18:37:49 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include "arg.h"

t_arg			*get_arg(int ac, char **av)
{
	t_arg		*ret;
	t_bool		state;
	int			i;

	if ((!(ret = (t_arg*)ft_memalloc(sizeof(*ret)))))
		return (NULL);
	ret->short_param = NULL;
	ret->long_param = NULL;
	ret->data_param = NULL;
	printf("zz\n");
	i = 1;
	state = TRUE;
	printf("xx\n");
	while (i < ac)
	{
		printf("xx %d\n", i);
		if (av[i][0] == '-')
			state = get_short_param(ret, av[i] + 1);
		//else if (av[ac][0] == '-' && av[i][1] && av[i][1] == '-')
			//state = get_long_param(ret, &(av[i]) + 2);
		//else
			//state = get_data(ret, av[i]);
		++i;
	}
	ret->state = state;
	return (ret);
}

static t_bool			is_present_short_param(t_string s, char c)
{
	int			i;

	printf("--\n");
	if (!s)
		return (FALSE);
	printf("--\n");
	i = 0;
	printf("--\n");
	while (s[i] && s[i] != c)
		i++;
	printf("bc\n");
	if (i == ft_strlen(s))
		return (FALSE);
	return (TRUE);
}

/* verification de la chaine
 *
 * verifie si il  est deja present
 */

t_bool			get_short_param(t_arg *a, t_string s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		printf("aa\n");
		if (ft_isalpha(s[i]) && !is_present_short_param(a->short_param, s[i]))
		{
		printf("cc\n");
			a->short_param = ft_strccat(a->short_param, s[i]);
		printf("dd %s\n", a->short_param);
		}
		else
			return (FALSE);
		printf("bb\n");
		i++;
	}
	return (TRUE);
}
