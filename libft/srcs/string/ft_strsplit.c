/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 01:36:48 by rdantzer          #+#    #+#             */
/*   Updated: 2015/01/29 04:24:55 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	int			is_in_word;
	int			len;

	is_in_word = 0;
	len = 0;
	while (*s)
	{
		if (is_in_word == 0 && *s != c)
		{
			len++;
			is_in_word = 1;
		}
		if (is_in_word && *s == c)
			is_in_word = 0;
		s++;
	}
	return (len);
}

static void		fill_array(char **array, char const *s, char c)
{
	int			is_in_word;
	int			start;
	int			len;

	is_in_word = 0;
	len = 0;
	start = 0;
	while (s[len])
	{
		if (is_in_word == 0 && s[len] != c)
		{
			is_in_word = 1;
			start = len;
		}
		if (is_in_word && s[len] == c)
		{
			is_in_word = 0;
			*array = ft_strsub(s, start, len - start);
			++array;
		}
		++len;
	}
	if (is_in_word == 1)
		*array = ft_strsub(s, start, len - start);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**p;
	size_t		len;

	if (!s)
		return (0);
	len = word_count(s, c);
	p = (char **)malloc(sizeof(char *) * len + 2);
	if (p)
		fill_array(p, s, c);
	p[len] = 0;
	return (p);
}
