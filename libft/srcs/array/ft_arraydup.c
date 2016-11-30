/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 23:09:26 by rdantzer          #+#    #+#             */
/*   Updated: 2015/03/23 06:44:16 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_arraydup(char **array)
{
	const int	array_len = ft_arraylen(array);
	char		**new_array;
	int			i;

	i = -1;
	new_array = (char **)malloc(sizeof(char *) * (array_len + 1));
	while (array[++i])
		new_array[i] = ft_strdup(array[i]);
	array[i] = NULL;
	return (new_array);
}
