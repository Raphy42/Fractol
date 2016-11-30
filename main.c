/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 05:24:11 by rdantzer          #+#    #+#             */
/*   Updated: 2015/05/05 02:49:04 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>

static void		usage(void)
{
	ft_putendl("fractol help:");
	ft_putendl("usage: ./fractol [1-5]");
	ft_putendl("1.mandelbrot 2.julia 3.modulo 4.burning_ship 5.multibrot");
	ft_putendl("Keys: - - - - - - - - - - - - -");
	ft_putendl("B: launch the nebulabrot in a new window");
	ft_putendl("C: switch color palette");
	ft_putendl("F: switch fractal type");
	ft_putendl("P/; increment decrement multibrot roots");
	ft_putendl("O/I: increment decrement maximum iterations (2n)");
	ft_putendl("X: open current fractal in a new window");
	ft_fprintf(1, "%s %s %s %s: move fractal\n",
		"\u2190", "\u2191", "\u2193", "\u2192");
	ft_putendl("LEFT_CLICK MIDDLE_UP: zoom in");
	ft_putendl("RIGHT_CLICK MIDDLE_DOWN: zoom out");
	ft_putendl("NUMERIC_1: switch render mode");
	ft_putendl("ESCAPE: close the current window");
	ft_putendl("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

void			fractol_error(char *str, void *to_test)
{
	if (to_test != NULL)
		return ;
	usage();
	ft_putstr_fd("fractol: ", 2);
	ft_putendl_fd(str, 2);
	exit (EXIT_FAILURE);
}

static void		get_args(int argc, char **argv, t_fract *f)
{
	int			n;

	if (argc != 2)
		fractol_error("usage: ./fractol [1-5]", NULL);
	n = ft_atoi(argv[1]);
	if (n > 5)
		fractol_error("fractal doesn't exists", NULL);
	else
		switch_fractal_type(f, n - 1);
}

int				main(int argc, char **argv)
{
	t_fract		f;

	ft_bzero(&f, sizeof(t_fract));
	get_args(argc, argv, &f);
	init_env(&f);
	if (getppid() == 0)
		usage();
	f.render_mode(&f);
	mlx_mouse_hook(f.win, &mouse_hook, &f);
	mlx_hook(f.win, KEY_PRESS, KEY_PRESS_MASK, key_hook, &f);
	mlx_hook(f.win, MOTION_NOTIFY, PTR_MOTION_MASK, motion_hook, &f);
	mlx_loop(f.mlx);
	mlx_destroy_window(f.mlx, f.win);
	return (0);
}
