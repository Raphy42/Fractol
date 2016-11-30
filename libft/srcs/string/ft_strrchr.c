/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:50:06 by rdantzer          #+#    #+#             */
/*   Updated: 2014/11/12 16:08:44 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	size_t		len;

	len = ft_strlen(s);
	s += len;
	while ((*s != (char)c) && (len-- > 0))
		s--;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
