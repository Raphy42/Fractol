/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayappend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:12:09 by rdantzer          #+#    #+#             */
/*   Updated: 2015/02/26 15:13:12 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			**ft_arrayappend(char **array, char *str)
{
	const int	len = ft_arraylen(array);
	char		**new_array;
	int			i;

	i = -1;
	new_array = (char **)malloc(sizeof(char *) * (len + 2));
	while (array[++i])
		new_array[i] = ft_strdup(array[i]);
	new_array[i++] = ft_strdup(str);
	new_array[i] = NULL;
	return (new_array);
}
