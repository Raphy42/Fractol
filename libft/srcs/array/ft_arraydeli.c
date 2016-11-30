/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydeli.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:07:29 by rdantzer          #+#    #+#             */
/*   Updated: 2015/02/26 15:07:34 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				**ft_arraydeli(char **array, int i)
{
	const int		len = ft_arraylen(array);
	char			**new_array;
	int				j;
	int				k;

	j = -1;
	k = -1;
	if (i >= len)
		return (array);
	new_array = (char **)malloc(sizeof(char *) * len);
	while (++j < i)
		new_array[++k] = array[j];
	while (++j < len)
		new_array[++k] = array[j];
	new_array[j] = NULL;
	return (new_array);
}
