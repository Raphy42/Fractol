/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:58:15 by rdantzer          #+#    #+#             */
/*   Updated: 2015/01/01 23:19:30 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memalloc(size_t size)
{
	void		*ptr;

	ptr = (void *)malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_memset((char *)ptr, 0, size);
	return (ptr);
}
