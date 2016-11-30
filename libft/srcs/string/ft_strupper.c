/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 03:32:39 by rdantzer          #+#    #+#             */
/*   Updated: 2015/03/23 06:46:18 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strupper(char *str)
{
	if (str == NULL)
		return ;
	while (*str != '\0')
	{
		*str = ft_toupper(*str);
		str++;
	}
}
