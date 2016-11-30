/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_launcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 00:18:40 by rdantzer          #+#    #+#             */
/*   Updated: 2015/05/04 18:02:27 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenCL/OpenCL.h>
#include "fractol.h"
#include "mlx.h"
#include <stdio.h>

void			convert_int_to_img(int *values, t_fract *f)
{
	register int	pos;
	int				x;
	int				y;
	const int		max = WIN_X * WIN_Y;

	pos = 0;
	while (pos < max)
	{
		x = pos / WIN_X;
		y = pos % WIN_X;
		if (values[pos] == CL_MAX_ITERATION)
			put_pixel(f, x, y, 0);
		else	
			put_pixel(f, x, y, f->color(values[pos], f));
		pos++;
	}
}

int				opencl_render(t_fract *f)
{
	t_fract_opencl		f_ocl;
	cl_uint				i;
	size_t				buffer_size;
	int					*host_image;

	f_ocl.width = WIN_X;
	f_ocl.height = WIN_Y;
	buffer_size = sizeof(int) * f_ocl.width * f_ocl.height;
	host_image = (int *)ft_memalloc(buffer_size);
	ft_bzero(&f_ocl, sizeof(t_fract_opencl));
	f_ocl.width = WIN_X;
	f_ocl.height = WIN_Y;
	f_ocl.context = create_context(&f_ocl.num_devices);
	if(f_ocl.num_devices == 0)
	{
		ft_putendl("OpenCL: No compute devices found\n");
		exit (EXIT_FAILURE);
	}
	print_cl_infos(f_ocl.context);
	f_ocl.err = clGetContextInfo(f_ocl.context, CL_CONTEXT_DEVICES,
		sizeof(cl_device_id) * 16, &f_ocl.devices, NULL);
	get_cl_error("Getting context info", f_ocl.err);
	i = -1;
	while(++i < f_ocl.num_devices)
	{
		f_ocl.cmd_queue[i] = clCreateCommandQueue(f_ocl.context, f_ocl.devices[i], 0, &f_ocl.err);
		get_cl_error("Creating command queue", f_ocl.err);
	}
	f_ocl.image	= clCreateBuffer(f_ocl.context, CL_MEM_WRITE_ONLY, buffer_size, NULL, &f_ocl.err);
	get_cl_error("Creating buffer", f_ocl.err);
	f_ocl.kernel = load_kernel_from_file(f_ocl.context, KERNEL_FILENAME, f->opencl_kernel_name);
	f_ocl.err |= clSetKernelArg(f_ocl.kernel, 0, sizeof(cl_mem), &f_ocl.image);
	f_ocl.err |= clSetKernelArg(f_ocl.kernel, 1, sizeof(double), &f->max.i);
	f_ocl.err |= clSetKernelArg(f_ocl.kernel, 2, sizeof(double), &f->min.r);
	f_ocl.err |= clSetKernelArg(f_ocl.kernel, 3, sizeof(double), &f->zoom_x);
	f_ocl.err |= clSetKernelArg(f_ocl.kernel, 4, sizeof(double), &f->zoom_y);
	get_cl_error("Setting kernel arg", f_ocl.err);
	f_ocl.device_work_size[0] = f_ocl.width;
	f_ocl.device_work_size[1] = f_ocl.height / f_ocl.num_devices;
	i = -1;
	while(++i < f_ocl.num_devices)
	{
		f_ocl.device_work_offset[0] = 0;
		f_ocl.device_work_offset[1] = f_ocl.device_work_size[1] * i;
		f_ocl.offset = f_ocl.device_work_offset[1] * f_ocl.width;
		f_ocl.err = clEnqueueNDRangeKernel(f_ocl.cmd_queue[i], f_ocl.kernel, 2,
			f_ocl.device_work_offset, f_ocl.device_work_size, NULL, 0, NULL, NULL);
		get_cl_error("Running kernel", f_ocl.err);
		f_ocl.err = clEnqueueReadBuffer(f_ocl.cmd_queue[i], f_ocl.image, CL_FALSE,
			f_ocl.offset, buffer_size / f_ocl.num_devices,
			host_image, 0, NULL, NULL);
		get_cl_error("Reading buffer", f_ocl.err);
	}
	i = -1;
	while(++i < f_ocl.num_devices)
		clFinish(f_ocl.cmd_queue[i]);
	convert_int_to_img(host_image, f);
	clReleaseMemObject(f_ocl.image);
	i = -1;
	while (++i < f_ocl.num_devices)
		clReleaseCommandQueue(f_ocl.cmd_queue[i]);
	clReleaseContext(f_ocl.context);
	free(host_image);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (CL_SUCCESS);
}
