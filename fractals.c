/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 05:07:53 by rdantzer          #+#    #+#             */
/*   Updated: 2015/04/30 19:37:11 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <string.h>
#include <time.h>

int				mandelbrot(int x, int y, t_fract *f)
{
	t_complex				c;
	t_complex				new;
	t_complex				old;
	register int			i;

	ft_bzero(&new, sizeof(t_complex));
	ft_bzero(&old, sizeof(t_complex));
	c.i = f->max.i - (long double)y * f->zoom_y;
	c.r = f->min.r + (long double)x * f->zoom_x;
	i = -1;
	while (++i < f->max_loop)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + c.r;
		new.i = 2 * old.r * old.i + c.i;
		if ((new.r * new.r + new.i * new.i) > 4)
			break ;
	}
	f->im = old.i;
	f->re = old.r;
	return (i);
}

int				julia(int x, int y, t_fract *f)
{
	t_complex				new;
	t_complex				old;
	register int			i;

	i = 0;
	new.i = f->max.i - (long double)y * f->zoom_y;
	new.r = f->min.r + (long double)x * f->zoom_x;
	while (i < f->max_loop)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + f->real;
		new.i = 2 * old.r * old.i + f->complex;
		if (new.r * new.r + new.i * new.i > 4)
			break ;
		i++;
	}
	f->im = old.i;
	f->re = old.r;
	return (i);
}

int				menger_sponge(int x, int y, t_fract *f)
{
	register int		i;
	long double			k;
	long double			l;

	i = 0;
	k = (x) / f->zoom_x;
	l = (y) / f->zoom_y;
	while ((k > 0 || l > 0) && i < f->max_loop)
	{
		if ((int)k % 3 == 1 && (int)l % 3 == 1)
			return (0);
		k /= 3;
		l /= 3;
		i++;
	}
	return (10);
}

int				burning_ship(int x, int y, t_fract *f)
{
	register int		i;
	t_complex			z;
	t_complex			z2;

	i = 0;
	f->c.r = f->min.r + (long double)x * f->zoom_x;
	f->c.i = f->max.i - (long double)y * f->zoom_y;
	z.r = f->c.r;
	z.i = f->c.i;
	z2.r = 0;
	z2.i = 0;
	while (i < f->max_loop)
	{
		z.i = z2.r * z2.r - z2.i * z2.i - f->c.r;
		z.r = 2 * fabsl(z2.r * z2.i) - f->c.i;
		z2.i = z.i;
		z2.r = z.r;
		if ((z2.r * z2.r + z2.i * z2.i) > 4)
			break ;
		i++;
	}
	return (i);
}

int				multibrot(int x, int y, t_fract *f)
{
	t_complex				new;
	t_complex				old;
	t_complex				p;
	register int			i;

	ft_bzero(&new, sizeof(t_complex));
	ft_bzero(&old, sizeof(t_complex));
	p.i = f->max.i - (long double)y * f->zoom_y;
	p.r = f->min.r + (long double)x * f->zoom_x;
	i = -1;
	while (++i < f->max_loop)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = powl((old.r * old.r + old.i * old.i), f->power / 2)
			* cos(f->power * atan2(old.i, old.r)) + p.r;
		new.i = powl((old.r * old.r + old.i * old.i), f->power / 2)
			* sin(f->power * atan2(old.i, old.r)) + p.i;
		if ((new.r * new.r + new.i * new.i) > 4)
			break ;
	}
	f->im = new.i;
	f->re = new.r;
	return (i);
}
