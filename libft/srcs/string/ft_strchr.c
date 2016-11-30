/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:38:07 by rdantzer          #+#    #+#             */
/*   Updated: 2014/11/12 16:08:18 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	char		*buf;

	buf = (char *)s;
	while (*buf && *buf != (char)c)
	{
		++buf;
	}
	if (*buf == (char)c)
		return (buf);
	return (NULL);
}
