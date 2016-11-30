/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_helper.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 01:26:12 by rdantzer          #+#    #+#             */
/*   Updated: 2015/04/29 23:59:54 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_CL_HELPER
# define OPEN_CL_HELPER

#include <OpenCL/OpenCL.h>
#include "fractol.h"
#include "libft.h"

char		*load_kernel_source(const char *filename);
cl_kernel	load_kernel_from_file(cl_context context,
	const char *filename, char *fractal);
cl_context	create_context(cl_uint *num_devices);
void		print_cl_infos(cl_context context);
void		get_cl_error(char *debug, cl_int err);
int			opencl_render(t_fract *f);

#endif
