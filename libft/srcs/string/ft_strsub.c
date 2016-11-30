/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:42:44 by rdantzer          #+#    #+#             */
/*   Updated: 2014/11/24 22:18:13 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;

	p = ft_strnew(len + 1);
	if (s && (int)len > 0)
	{
		ft_strncpy(p, s + start, len);
		return (p);
	}
	return (p);
}
