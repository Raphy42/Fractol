/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:15:41 by rdantzer          #+#    #+#             */
/*   Updated: 2015/01/29 04:24:52 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	if (*s2 == '\0')
		return ((char*)s1);
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s2[j] != '\0' && (i + j) < n)
		{
			if (s1[i + j] != s2[j] || s2[j] == '\0')
				break ;
			j++;
		}
		if (s2[j] == '\0')
			return (i + (char*)s1);
		i++;
	}
	return (NULL);
}
