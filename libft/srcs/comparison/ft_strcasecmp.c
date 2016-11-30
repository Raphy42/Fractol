/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 03:26:46 by rdantzer          #+#    #+#             */
/*   Updated: 2015/03/23 06:45:04 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcasecmp(const char *s1, const char *s2)
{
	unsigned char	c1;
	unsigned char	c2;

	while (1)
	{
		c1 = ft_tolower(*s1++);
		c2 = ft_tolower(*s2++);
		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0')
			return (0);
	}
}
