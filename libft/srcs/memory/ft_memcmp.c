/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:44:12 by rdantzer          #+#    #+#             */
/*   Updated: 2015/01/01 23:37:24 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buf1;
	unsigned char	*buf2;
	size_t			i;

	buf1 = (unsigned char *)s1;
	buf2 = (unsigned char *)s2;
	i = 0;
	if (buf1 && buf2)
	{
		while (i < n && buf1[i] == buf2[i])
			++i;
		if (i == n)
			return (0);
		else
			return ((int)(buf1[i] - buf2[i]));
	}
	return (0);
}
