/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:09:05 by rdantzer          #+#    #+#             */
/*   Updated: 2015/01/01 23:15:51 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int			ft_abs(int n)
{
	int				nb;

	nb = (n < 0) ? -n : n;
	return (nb);
}

char				*ft_itoa(int n)
{
	int				size;
	int				i;
	char			*str;

	str = NULL;
	size = (n < 0) ? 2 : 1;
	i = n;
	while (i > 9 || i < -9)
	{
		size++;
		i = ft_abs(i / 10);
	}
	if ((str = (char *)malloc((size + 1) * sizeof(*str))))
	{
		str[size--] = '\0';
		i = n;
		while (size + 1)
		{
			str[size--] = '0' + ft_abs(i % 10);
			i = ft_abs(i / 10);
		}
		if (n < 0)
			str[0] = '-';
	}
	return (str);
}
