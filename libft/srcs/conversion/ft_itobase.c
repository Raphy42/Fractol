/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 14:40:12 by rdantzer          #+#    #+#             */
/*   Updated: 2015/03/23 06:44:55 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_itobase(long nb, int base)
{
	char		*str;
	int			i;
	long		tmp;
	char		*base_str;

	base_str = BASE;
	if (nb == 0 || base <= 1)
		return (ft_strdup("0"));
	tmp = nb;
	i = 1;
	while ((tmp /= base) != 0)
		i++;
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	tmp = nb;
	while (--i >= 0)
	{
		str[i] = base_str[tmp % base];
		tmp /= base;
	}
	return (str);
}
