/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 09:05:45 by rdantzer          #+#    #+#             */
/*   Updated: 2015/02/16 21:32:51 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_atod(const char *str)
{
	double		nb;
	double		part;
	double		sign;

	while (ft_isspace(*str))
		str++;
	part = 0.0;
	sign = (*str == '-') ? -1.0 : 1.0;
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	nb = 0.0;
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 + (*(str++) - '0');
	if (*str == '.' || *str == ',')
	{
		while (*(++str) >= '0' && *str <= '9')
			part = 0.0;
		while (*(--str) >= '0' && *str <= '9')
			part = (part + (*str - '0')) / 10.0;
	}
	return ((nb + part) * sign);
}
