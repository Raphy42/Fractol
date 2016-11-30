/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 01:26:27 by rdantzer          #+#    #+#             */
/*   Updated: 2015/01/02 01:07:26 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(const char *s, char (*f)(char))
{
	char			*str;
	char			*p;

	p = NULL;
	if (s != NULL && f != NULL)
	{
		str = ft_strdup(s);
		if (!str)
			return (NULL);
		p = str;
		while (*str)
		{
			*str = f(*str);
			str++;
		}
	}
	return (p);
}
