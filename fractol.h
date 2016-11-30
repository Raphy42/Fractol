/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 08:38:03 by rdantzer          #+#    #+#             */
/*   Updated: 2015/05/05 01:08:39 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <OpenCL/OpenCL.h>

# define CL_MAX_ITERATION		120000
# define BUDDHA_WIN_X			1440
# define BUDDHA_WIN_Y			1440
# define KERNEL_FILENAME		"fractals.cl"
# define KEY_ALPHA_B			11
# define KEY_ALPHA_C			8
# define KEY_ALPHA_F			3
# define KEY_ALPHA_I			34
# define KEY_ALPHA_P			35
# define KEY_UNDER_P			41
# define KEY_ALPHA_O			31
# define KEY_ALPHA_S			1
# define KEY_ALPHA_X			7
# define KEY_DOWN				125
# define KEY_ESC				53
# define KEY_KP_0				82
# define KEY_KP_1				83
# define KEY_KP_2				84
# define KEY_KP_3				85
# define KEY_KP_4				86
# define KEY_KP_5				87
# define KEY_KP_6				88
# define KEY_KP_7				89
# define KEY_KP_8				91
# define KEY_KP_9				92
# define KEY_KP_DOT				65
# define KEY_KP_ENTER			6
# define KEY_KP_MINUS			78
# define KEY_KP_PLUS			69
# define KEY_LEFT				123
# define KEY_MOUSE_DOWN			4
# define KEY_MOUSE_LEFT			1
# define KEY_MOUSE_RIGHT		2
# define KEY_MOUSE_UP			5
# define KEY_PAGE_DOWN			121
# define KEY_PAGE_UP			116
# define KEY_PRESS				2
# define KEY_PRESS_MASK			(1L<<0)
# define KEY_RIGHT				124
# define KEY_UP					126
# define LOG2					0.69314718055994530941723212145817
# define MAX_DEVICE				16
# define MAX_ITER				64
# define MOTION_NOTIFY			6
# define PTR_MOTION_MASK		(1L<<6)
# define THREADS				4
# define TITLE					"Fractol"
# define WIN_X					800
# define WIN_Y					800
# define ZOOM					1.10
# define FREQUENCY				.5

enum				e_type
{
	MANDELBROT = 1,
	JULIA,
	MENGER_SPONGE,
	BURNING_SHIP,
	MULTIBROT,
	FRACTAL_COUNT
};

typedef struct			s_nebula
{
	int					pos;
	unsigned int		*r;
	unsigned int		*g;
	unsigned int		*b;
	int					max_1;
	int					max_2;
	int					max_3;
	int					(*color)(struct s_nebula *);
}						t_nebula;

typedef struct			s_pos
{
	double				x;
	double				y;
}						t_pos;

typedef struct			s_tab
{
	int					name;
	void				*f;
	char				*opencl_kernel_name;
}						t_tab;

typedef struct			s_rgb
{
	int					red;
	int					green;
	int					blue;
}						t_rgb;

typedef struct			s_complex
{
	double				r;
	double				i;
}						t_complex;

typedef struct			s_fract_opencl
{
	char				*kernel_source;
	cl_uint				num_devices;
	cl_kernel			kernel;
	cl_command_queue	cmd_queue[16];
	cl_context			context;
	cl_mem				image;
	cl_device_id		devices[16];
	cl_int				err;
	cl_uint				width;
	cl_uint				height;
	size_t				device_work_size[2];
	size_t				device_work_offset[2];
	size_t				offset;
}						t_fract_opencl;


typedef struct			s_fract
{
	char				*dat;
	char				*opencl_kernel_name;
	double				center_x;
	double				center_y;
	double				complex;
	double				im;
	t_complex			max;
	t_complex			min;
	t_complex			z;
	t_complex			c;
	double				move_x;
	double				move_y;
	double				re;
	double				real;
	double				zoom_x;
	double				zoom_y;
	int					(*color)(int , struct s_fract *);
	int					(*render_mode)(struct s_fract *);
	int					(*fractal_type)(int , int, struct s_fract *);
	int					bpp;
	int					endian;
	int					line_size;
	int					power;
	int					max_loop;
	int					stop_move;
	int					type;
	int					x;
	int					y;
	int					x1;
	int					x2;
	int					y1;
	int					y2;
	void				*img;
	void				*mlx;
	void				*win;
	void				*buddha_win;
}						t_fract;

typedef struct		s_th_fract
{
	t_fract			*f;
	int				part;
}					t_th_fract;

#include "open_cl_helper.h"

void				fractol_error(char *str, void *to_test);

int					mandelbrot(int x, int y, t_fract *f);
int					julia(int x, int y, t_fract *f);
int					menger_sponge(int x, int y, t_fract *f);
int					burning_ship(int x, int y, t_fract *f);
int					multibrot(int x, int y, t_fract *f);


void				init_env(t_fract *f);
int					threaded_render(t_fract *f);
int					key_hook(int key, t_fract *param);
int					motion_hook(int x, int y, t_fract *param);
int					mouse_hook(int click, int x, int y, t_fract *e);
int					get_colors(int i, t_fract *f);
void				put_pixel(t_fract *e, int x, int y, int color);
int					get_greyscale_color(int i, t_fract *f);
int					get_wiki_color(int i, t_fract *f);
int					get_rainbow_color(int i, t_fract *f);
int					get_smoothed_greyscale(int i, t_fract *f);
int					get_smoothed_rainbow_color(int i, t_fract *f);
int					get_smoothed_wiki_color(int i, t_fract *f);

void				switch_fractal_type(t_fract *f, int roll);
void				switch_color(t_fract *f);
void				switch_render(t_fract *f);
void				switch_fractal(t_fract *f);
void				launch_fractal(t_fract *f, int is_budda);

#endif
