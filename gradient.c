/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 20:45:59 by rdantzer          #+#    #+#             */
/*   Updated: 2015/05/05 00:49:38 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static int			return_wiki_colors(int n)
{
	const int		colors[16] = {
		0x421E0F,
		0x19071A,
		0x09012F,
		0x040449,
		0x000764,
		0x0C2C8A,
		0x1852B1,
		0x397DD1,
		0x86B5D1,
		0xD3ECF8,
		0xF1E9BF,
		0xF8C95F,
		0xFFAA00,
		0xCC8000,
		0x995700,
		0x6A3403
	};
	return (colors[n]);
}

int 				get_wiki_color(int i, t_fract *f)
{
	int				n;

	if (i == f->max_loop || i < 0)
		return (0x000000);
	n = i % 16;
	return (return_wiki_colors(n));
}

int					get_greyscale_color(int i, t_fract *f)
{
	int				n;
	const int		s = f->max_loop;

	if (i == f->max_loop)
		return (0x000000);
	n = i;
	return (((n * 255 / s) << 16) + ((n * 255 / s) << 8) + n * 255 / s);
}

int					get_rainbow_color(int i, t_fract *f)
{
	const float		frequency = .1;
	t_rgb			color;

	if (i == f->max_loop)
		return (0x000000);
	color.red = sin(frequency * i + 0) * 127 + 128;
	color.green = sin(frequency * i + 2) * 127 + 128;
	color.blue = sin(frequency * i + 4) * 127 + 128;
	return ((color.red << 16) + (color.green << 8) + color.blue);
}
