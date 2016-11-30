/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:45:43 by rdantzer          #+#    #+#             */
/*   Updated: 2014/11/11 14:46:07 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	if (s1 && s2)
	{
		if (ft_strncmp(s1, s2, n) == 0)
			i = 1;
		else
			i = 0;
		return (i);
	}
	return (0);
}
