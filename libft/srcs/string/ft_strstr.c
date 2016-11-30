/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:15:21 by rdantzer          #+#    #+#             */
/*   Updated: 2014/12/17 17:53:38 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*str;
	size_t	len;

	str = (char *)s1;
	len = ft_strlen(s2);
	if (*str == 0)
		return (str);
	while (*str)
	{
		if (ft_strncmp(str, s2, len) == 0)
			return (str);
		str++;
	}
	return (NULL);
}
