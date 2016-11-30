/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 22:52:06 by rdantzer          #+#    #+#             */
/*   Updated: 2015/03/23 06:45:43 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strndup(const char *s, size_t n)
{
	char			*result;
	size_t			len;

	len = ft_strlen(s);
	if (n < len)
		len = n;
	result = ft_strnew(len);
	if (!result)
		return (NULL);
	return ((char *)ft_memcpy(result, s, len));
}
