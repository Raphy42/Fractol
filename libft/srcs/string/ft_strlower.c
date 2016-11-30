/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 03:30:26 by rdantzer          #+#    #+#             */
/*   Updated: 2015/03/23 06:45:14 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strlower(char *str)
{
	if (str == NULL)
		return ;
	while (*str != '\0')
	{
		*str = ft_tolower(*str);
		str++;
	}
}
