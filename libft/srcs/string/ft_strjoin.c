/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 21:12:56 by rdantzer          #+#    #+#             */
/*   Updated: 2015/01/05 23:43:48 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(const char *s1, const char *s2)
{
	size_t		len1;
	size_t		len2;
	char		*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = ft_strnew(len1 + len2);
	if (str == NULL)
		return (NULL);
	if (len1 > 0)
		ft_memcpy(str, s1, len1);
	if (len2 > 0)
		ft_memcpy(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}
