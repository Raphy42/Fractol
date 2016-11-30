/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:40:11 by rdantzer          #+#    #+#             */
/*   Updated: 2015/01/01 22:36:57 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp;
	const char	*src2;

	src2 = src;
	tmp = dst;
	while (n > 0)
	{
		*tmp = *src2;
		tmp++;
		src2++;
		n--;
	}
	return (dst);
}
