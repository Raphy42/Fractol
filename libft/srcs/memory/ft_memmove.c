/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:17:13 by rdantzer          #+#    #+#             */
/*   Updated: 2015/01/01 22:37:05 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*s1;
	const char	*s2;

	s1 = dst;
	s2 = src;
	if (len == 0)
		return ((void *)0);
	if (s1 < s2)
		return (ft_memcpy(s1, s2, len));
	s1 += len;
	s2 += len;
	while (len--)
		*--s1 = *--s2;
	return (dst);
}
