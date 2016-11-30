/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:21:21 by rdantzer          #+#    #+#             */
/*   Updated: 2014/11/12 16:07:50 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*buf2;
	const unsigned char	*buf1;

	buf1 = (const unsigned char *)src;
	buf2 = (unsigned char *)dst;
	if (dst && src && n > 0)
	{
		while (*buf1 != (unsigned char)c && n)
		{
			*buf2++ = *buf1++;
			--n;
		}
		if (*buf1 == (unsigned char)c && n != 0)
		{
			*buf2++ = *buf1;
		}
		return ((n == 0) ? 0 : buf2);
	}
	return (0);
}
