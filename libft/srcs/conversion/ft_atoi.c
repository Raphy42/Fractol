/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:23:17 by rdantzer          #+#    #+#             */
/*   Updated: 2015/03/23 19:02:18 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*skip_spaces(char *str)
{
	while (ft_isspace(*str))
		str++;
	return (str);
}

static t_ull			char_to_int(const char *str, int *neg)
{
	t_ull				i;

	i = 0;
	while (*str && ft_isdigit((int)*str))
	{
		i = i * 10 + *str - '0';
		str++;
	}
	if (i == (t_ull)INT_MAX)
		return (INT_MAX);
	else if (i > (t_ull)INT_MAX + 1 && i < (t_ull)LONG_MAX && *neg == -1)
	{
		*neg = 1;
		return (LONG_MAX - i + 1);
	}
	else if (i > (t_ull)INT_MAX + 1 && i < (t_ull)LONG_MAX)
		return (LONG_MAX - i - 3);
	else if (i > (t_ull)LONG_MAX)
	{
		*neg = *neg == -1 ? 0 : 1;
		return (-1);
	}
	else
		return (i);
}

int						ft_atoi(const char *str)
{
	int					negative;

	negative = 1;
	if (str == NULL)
		return (0);
	str = skip_spaces((char *)str);
	while (*str == '0')
		str++;
	if (*str == '-')
	{
		negative = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return ((int)char_to_int(str, &negative) * negative);
}
