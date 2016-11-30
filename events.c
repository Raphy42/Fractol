/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 07:17:10 by rdantzer          #+#    #+#             */
/*   Updated: 2015/05/05 02:42:45 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fractol.h"
#include <stdlib.h>
#include <math.h>
#include <signal.h>

static int	key_hook_switch(int key, t_fract *e)
{
	if (key == KEY_ALPHA_C)
		switch_color(e);
	else if (key == KEY_KP_1)
		switch_render(e);
	else if (key == KEY_ALPHA_S)
		return (e->stop_move = !e->stop_move);
	else if (key == KEY_ALPHA_F)
		switch_fractal(e);
	else if (key == KEY_ALPHA_P)
		e->power++;
	else if (key == KEY_UNDER_P)
		e->power == 0 ? 0 : e->power--;
	else if (key == KEY_ALPHA_B)
		launch_fractal(e, 1);
	else if (key == KEY_ALPHA_X)
		launch_fractal(e, 0);
	else
		return (0);
	return (e->render_mode(e));
}

int			key_hook(int key, t_fract *e)
{
	if (key == KEY_ESC)
		exit (0);
	else if (key == KEY_LEFT)
		e->move_x += 0.1;
	else if (key == KEY_RIGHT)
		e->move_x -= 0.1;
	else if (key == KEY_UP)
		e->move_y += 0.1;
	else if (key == KEY_DOWN)
		e->move_y -= 0.1;
	else if (key == KEY_ALPHA_I)
		e->max_loop = e->max_loop / 2 == 4 ? 8 : e->max_loop / 2;
	else if (key == KEY_ALPHA_O)
		e->max_loop = e->max_loop * 2 == 1024 ? 512 : e->max_loop * 2;
	else
		return (key_hook_switch(key, e));
	return (e->render_mode(e));
}

int			motion_hook(int x, int y, t_fract *e)
{
	if (x >= 0 && y >= 0 && x <= WIN_X && y <= WIN_Y && !e->stop_move
		&& e->type == JULIA)
	{
		e->complex = e->max.i - (double)y * e->zoom_y;
		e->real = e->min.r + (double)x * e->zoom_x;
	}
	else
		return (0);
	return (e->render_mode(e));
}

int			mouse_hook(int click, int x, int y, t_fract *e)
{
	t_complex	c;

	c.r = e->max.r - e->min.r;
	c.i = e->max.i - e->min.i;
	e->move_x = (double)x / WIN_X * c.r - c.r / 2 + e->move_x;
	e->move_y = (double)(WIN_Y - y) / WIN_Y * c.i - c.i / 2 + e->move_y;
	c.r = (click == 1 || click == 4) ? c.r / 1.5 : c.r;
	c.i = (click == 1 || click == 4) ? c.i / 1.5 : c.i;
	c.r = (click == 2 || click == 5) ? c.r * 1.5 : c.r;
	c.i = (click == 2 || click == 5) ? c.i * 1.5 : c.i;
	e->min.r = e->move_x - c.r / 2;
	e->max.r = e->move_x + c.r / 2;
	e->min.i = e->move_y - c.i / 2;
	e->max.i = e->move_y + c.i / 2;
	e->zoom_x = (e->max.r - e->min.r) / (WIN_X - 1);
	e->zoom_y = (e->max.i - e->min.i) / (WIN_Y - 1);
	return (e->render_mode(e));
}
