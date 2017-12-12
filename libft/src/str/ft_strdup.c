/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:38:31 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 12:30:27 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/libft.h"

char		*ft_strdup(const char *src)
{
	char	*s;
	int		i;

	i = 0;
	s = NULL;
	s = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!s)
		return (NULL);
	while (src[i] != '\0')
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
