/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 15:54:11 by rdantzer          #+#    #+#             */
/*   Updated: 2015/05/04 23:37:34 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"

void		switch_fractal_type(t_fract *f, int roll)
{
	const t_tab	tab[FRACTAL_COUNT] = {
		{MANDELBROT, &mandelbrot, "mandelbrot"},
		{JULIA, &julia, "julia"},
		{MENGER_SPONGE, &menger_sponge, NULL},
		{BURNING_SHIP, &burning_ship, NULL},
		{MULTIBROT, &multibrot, NULL}
	};

	if (f->render_mode == opencl_render && roll > JULIA)
		return (switch_fractal_type(f, MANDELBROT));	
	f->type = tab[roll].name;
	f->fractal_type = tab[roll].f;
	f->opencl_kernel_name = tab[roll].opencl_kernel_name;
}

void			init_env(t_fract *f)
{
	f->mlx = mlx_init();
		fractol_error("failed to init mlx", f->mlx);
	f->win = mlx_new_window(f->mlx, WIN_X, WIN_Y, TITLE);
		fractol_error("failed to create new window", f->win);
	f->img = mlx_new_image(f->mlx, WIN_X, WIN_Y);
	f->dat = mlx_get_data_addr(f->img, &f->bpp, &f->line_size, &f->endian);
	f->color = &get_wiki_color;
	f->complex = 0.156;
	f->max_loop = MAX_ITER;
	f->power = 5;
	f->real = -0.8;
	f->render_mode = &threaded_render;
	f->max.r = 2.0;
	f->max.i = 2;
	f->min.r = -2.0;
	f->min.i = -2;
	f->zoom_x = (f->max.r - f->min.r) / (WIN_X - 1);
	f->zoom_y = (f->max.i - f->min.i) / (WIN_Y - 1);
}

void		switch_color(t_fract *f)
{
	if (f->color == get_greyscale_color)
		f->color = &get_wiki_color;
	else if (f->color == get_wiki_color)
		f->color = &get_rainbow_color;
	else
		f->color = &get_greyscale_color;
}

void		switch_render(t_fract *f)
{
	if (f->render_mode == opencl_render)
	{
		ft_putendl("Render engine: PTHREAD");
		f->render_mode = &threaded_render;
	}
	else
	{
		if (f->type > JULIA)
		{
			switch_fractal_type(f, MANDELBROT);
			ft_putendl("This fractal is currently unavailable with OpenCL");
		}
		ft_putendl("Render engine: OPENCL");
		f->render_mode = &opencl_render;
	}
}

void		switch_fractal(t_fract *f)
{
	static int	roll;

	if (roll > (FRACTAL_COUNT - 3))
		roll = -1;
	roll++;
	switch_fractal_type(f, roll);
}
