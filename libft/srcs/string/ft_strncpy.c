/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:16:03 by rdantzer          #+#    #+#             */
/*   Updated: 2014/11/12 16:08:42 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncpy(char *dst, const char *src, size_t n)
{
	char		*s;

	s = dst;
	while (n > 0 && *src != 0)
	{
		*s++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*s++ = 0;
		n--;
	}
	return (dst);
}
