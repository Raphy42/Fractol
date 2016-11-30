/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 04:26:09 by rdantzer          #+#    #+#             */
/*   Updated: 2015/04/29 16:32:46 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <pthread.h>
#include "mlx.h"
#include "fractol.h"

void			put_pixel(t_fract *e, int x, int y, int color)
{
	const unsigned int	bytes = e->bpp / 8;
	const unsigned int	p = x * bytes + y * e->line_size;
	size_t				i;

	i = 0;
	while (i < bytes)
	{
		e->dat[p + i] = color;
		color >>= 8;
		i++;
	}
}

static void		draw_fractal(t_fract *f, int part)
{
	register int		x;
	register int		y;
	int					stop;
	int					start;

	start = (WIN_Y / THREADS) * part;
	stop = (WIN_Y / THREADS) * (part + 1);
	x = 0;
	y = part;
	while (y < stop)
	{
		while (x < WIN_X)
		{
			put_pixel(f, x, y, f->color(f->fractal_type(x, y, f), f));
			x++;
		}
		x = 0;
		y++;
	}
}

static void		*threaderize_fractal(void *th)
{
	t_th_fract			*unth;

	unth = (t_th_fract *)th;
	draw_fractal(unth->f, unth->part);
	return (NULL);
}

int				threaded_render(t_fract *f)
{
	pthread_t			tid[THREADS];
	t_th_fract			f_threads[THREADS];
	register int		i;

	i = 0;
	while (i < THREADS)
	{
		f_threads[i].f = f;
		f_threads[i].part = i;
		pthread_create(&tid[i], NULL, threaderize_fractal, &f_threads[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(tid[i++], NULL);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
