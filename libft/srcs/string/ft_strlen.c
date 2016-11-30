/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:57:51 by rdantzer          #+#    #+#             */
/*   Updated: 2015/01/17 09:03:47 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_strlen(const char *s)
{
	register const char	*p;

	if (s == NULL)
		return (0);
	p = s;
	while (*p)
		p++;
	return (p - s);
}
