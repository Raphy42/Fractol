/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:33:22 by rdantzer          #+#    #+#             */
/*   Updated: 2014/11/19 19:16:16 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*buf;
	size_t				i;

	i = 0;
	buf = (unsigned char *)s;
	if (buf && i < n)
	{
		while (i < n && buf[i] != (unsigned char)c)
			++i;
		if (i < n && buf[i] == (unsigned char)c)
			return ((void *)buf + i);
	}
	return (NULL);
}
