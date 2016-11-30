/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 21:12:22 by rdantzer          #+#    #+#             */
/*   Updated: 2015/01/29 03:25:01 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(const char *s)
{
	size_t		start;
	size_t		end;
	size_t		length;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	start = 0;
	while (ft_isspace(s[start]))
		start++;
	if (start == length)
		return (ft_strdup(""));
	end = length - 1;
	while (ft_isspace(s[end]))
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
