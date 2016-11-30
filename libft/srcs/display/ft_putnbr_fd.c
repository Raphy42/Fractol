/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:14:28 by rdantzer          #+#    #+#             */
/*   Updated: 2015/01/01 22:45:34 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	char		*tmp;

	tmp = ft_itoa(n);
	if (tmp != NULL)
	{
		ft_putstr_fd(tmp, fd);
		free(tmp);
	}
}
