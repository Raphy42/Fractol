/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 05:08:48 by rdantzer          #+#    #+#             */
/*   Updated: 2015/05/05 02:25:40 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>
#include <time.h>
#include <stdio.h>

int					rainbow_color(t_nebula *n)
{
	t_rgb			c;
	const float		frequency = 0.9;

	c.red = sin(frequency * trunc(255 * sqrt(n->r[n->pos]) / sqrt(n->max_1))
		+ 0) * 127 + 128;
	c.green = sin(frequency * trunc(255 * sqrt(n->g[n->pos]) / sqrt(n->max_2))
		+ 2) * 127 + 128;
	c.blue = sin(frequency * trunc(255 * sqrt(n->b[n->pos]) / sqrt(n->max_3))
		+ 4) * 127 + 128;
	return ((c.red << 16) + (c.green << 8) + c.blue);
}

int					nebula_color(t_nebula *n)
{
	t_rgb			c;

	c.red = trunc(255 * sqrt(n->r[n->pos]) / sqrt(n->max_1));
	c.green = trunc(255 * sqrt(n->g[n->pos]) / sqrt(n->max_2));
	c.blue = trunc(255 * sqrt(n->b[n->pos]) / sqrt(n->max_3));
	return ((c.red << 16) + (c.green << 8) + c.blue);
}

int					greyscale_color(t_nebula *n)
{
	int				c;

	c = trunc(255 * sqrt(n->r[n->pos]) / sqrt(n->max_1));
	return ((c << 16) + (c << 8) + c);
}

static void			convert_int_to_img(t_nebula *n, t_fract *f)
{
	int				x;
	int				y;
	const int		max = BUDDHA_WIN_X * BUDDHA_WIN_Y;

	n->pos = 0;
	while (n->pos < max)
	{
		if (n->r[n->pos] == 0)
			mlx_pixel_put(f->mlx, f->win, x, y, 0);
		x = n->pos / BUDDHA_WIN_X;
		y = n->pos % BUDDHA_WIN_X;
		mlx_pixel_put(f->mlx, f->win, x, y, n->color(n));
		n->pos++;
	}
}

static int			mandel_iter(int bailout, long double x0, long double y0, int *n, t_pos *seq)
{
	int i;
	long double x=0,y=0,xnew,ynew;

	*n = 0;
	for (i=0;i<bailout;i++) {
		xnew = x * x - y * y + y0;
		ynew = 2 * x * y + x0;
		seq[i].x = xnew;
		seq[i].y = ynew;
		if (xnew*xnew + ynew*ynew > 10) {
			*n = i;
			return(1);   
		}
		x = xnew;
		y = ynew;
	}

	return(0);
}

int			key_hook(int key, t_fract *e)
{
	(void)e;
	if (key == KEY_ESC)
		exit (0);
	return (0);
}


int							get_max_color(unsigned int *tab)
{
	unsigned int			max = 0;
	int						pos = 0;
	for (pos = 0; pos < BUDDHA_WIN_X * BUDDHA_WIN_Y; pos++)
	{
		if (tab[pos] > max)
			max = tab[pos];
		pos++;
	}
	return (max);
}

unsigned int				*buddhabrot(int bailout, int iter)
{
	t_pos			*sequence;
	int				n, i, ix, iy;
	long double			x, y;
	unsigned int *image = (unsigned int *)malloc(BUDDHA_WIN_X * BUDDHA_WIN_Y * sizeof(unsigned int));

	sequence = (t_pos *)malloc(sizeof(t_pos) * iter);
	ft_bzero(sequence, sizeof(t_pos) * iter);
	ft_bzero(image, sizeof(int) * BUDDHA_WIN_X * BUDDHA_WIN_Y);
	srand48((unsigned int)time(NULL));
	for (int t = 0; t < bailout; t++)
	{
		ft_fprintf(2, "Buddhabrot: Processing: %f%%\r", (float)t * 100 / (float)bailout);
		fflush(stdout);
		for (int tt = 0; tt < 1000000; tt++)
		{
			x = 6 * drand48() - 3;
			y = 6 * drand48() - 3;
			if (mandel_iter(iter, x, y, &n, sequence))
			{
				for (i = 0; i < n; i++)
				{
					ix = 0.3 * BUDDHA_WIN_X * (sequence[i].x + 0.5) + BUDDHA_WIN_X / 2;
					iy = 0.3 * BUDDHA_WIN_Y * sequence[i].y + BUDDHA_WIN_Y / 2;
					if (ix >= 0 && iy >= 0 && ix < BUDDHA_WIN_X && iy < BUDDHA_WIN_Y)
						image[iy*BUDDHA_WIN_X+ix]++;
				}
			}
		}
	}
	return (image);
}

int					main(void)
{
	t_fract						f;
	t_nebula					e;

	ft_bzero(&f, sizeof(t_fract));
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, BUDDHA_WIN_X, BUDDHA_WIN_Y, "buddhabrot");
	e.color = &greyscale_color;
	e.r = buddhabrot(1, 5000);
	e.g = buddhabrot(500, 500);
	e.b = buddhabrot(500, 50);
	e.max_1 = get_max_color(e.r);
	e.max_2 = get_max_color(e.g);
	e.max_3 = get_max_color(e.b);
	convert_int_to_img(&e, &f);
	ft_fprintf(2, "Buddhabrot: rendering done\nPress [ESCAPE] to quit");
	mlx_hook(f.win, KEY_PRESS, KEY_PRESS_MASK, key_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}
