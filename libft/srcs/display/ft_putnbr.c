/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:09:59 by rdantzer          #+#    #+#             */
/*   Updated: 2015/01/01 22:44:54 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr(int n)
{
	char		*tmp;

	tmp = ft_itoa(n);
	if (tmp != NULL)
	{
		ft_putstr(tmp);
		free(tmp);
	}
}
