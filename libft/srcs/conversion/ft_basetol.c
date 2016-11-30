/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basetol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 12:22:39 by rdantzer          #+#    #+#             */
/*   Updated: 2015/03/23 06:44:52 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_strchri(char *str, char c)
{
	char			*tmp;

	tmp = (char *)str;
	while (*tmp != c)
	{
		if (*tmp == '\0')
			return (-1);
		tmp++;
	}
	return (tmp - str);
}

long				ft_basetol(const char *str, int base)
{
	int				i;
	long			nb;

	nb = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		nb *= base;
		nb += ft_strchri(BASE, str[i]);
	}
	return (nb);
}
