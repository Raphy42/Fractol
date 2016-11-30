/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 22:33:53 by rdantzer          #+#    #+#             */
/*   Updated: 2015/04/29 22:34:26 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenCL/OpenCl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "fractol.h"

const char	*g_cl_errors[] = {
	"Device not found",
	"Device not available",
	"Compiler not available",
	"Memory object allocation failure",
	"Out of resources",
	"Out of host memory",
	"Profiling info not available",
	"Memory copy overlap",
	"Image format mismatch",
	"Image format not supported",
	"Build program failure",
	"Map failure",
	"Invalid value",
	"Invaid device type",
	"Invalid platform",
	"Invalid device",
	"Invalid context",
	"Invalid queue properties",
	"Invalid command queue",
	"Invalid host pointer",
	"Invalid memory object",
	"Invalid image format descriptor",
	"Invalid image size",
	"Invalid sampler",
	"Invalid binary",
	"Invalid build options",
	"Invalid program",
	"Invalid program executable",
	"Invalid kernel name",
	"Invalid kernel defintion",
	"Invalid kernel",
	"Invalid argument index",
	"Invalid argument value",
	"Invalid argument size",
	"Invalid kernel arguments",
	"Invalid work dimension",
	"Invalid work group size",
	"Invalid work item size",
	"Invalid global offset",
	"Invalid event wait list",
	"Invalid event",
	"Invalid operation",
	"Invalid GL object",
	"Invalid buffer size",
	"Invalid mip level",
	"Invalid global work size"
};

char		*load_kernel_source(const char *filename)
{
	struct stat		stats;
	int				fd;
	char			*source;

	if (lstat(filename, &stats) == -1)
	{
		ft_putendl_fd("Missing or damaged kernel source", 2);
		exit (EXIT_FAILURE);
	}
	ft_fprintf(1, "Loaded kernel with a size of %u\n", (size_t)stats.st_size);
	source = ft_strnew(stats.st_size);
	fd = open(filename, O_RDONLY);
	read(fd, source, stats.st_size);
	close(fd);
	return (source);
}

cl_kernel	load_kernel_from_file(cl_context context,
	const char *filename, char *fractal)
{
	cl_program		program;
	cl_kernel		kernel;
	int				err;
	static char		*source;

	if (!source)
		source = load_kernel_source(filename);
	program = clCreateProgramWithSource(context, 1,
		(const char **)&source, NULL, &err);
	err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	kernel = clCreateKernel(program, fractal, &err);
	get_cl_error("kernel load ", err);
	return (kernel);
}

cl_context	create_context(cl_uint *num_devices)
{
	cl_int			err;
	cl_device_id	*devices;
	cl_device_id	cpus[MAX_DEVICE];
	cl_uint			num_cpus;
	cl_context		context;

	devices = malloc(16 * sizeof(cl_device_id));
	err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_CPU, MAX_DEVICE, cpus, &num_cpus);
	get_cl_error("Getting Cpu(s) IDs", err);
	err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, MAX_DEVICE,
		devices, num_devices);
	get_cl_error("Getting Gpu(s) IDs", err);
	if (err != CL_SUCCESS || *num_devices == 0)
	{
		devices = cpus;
		*num_devices = num_cpus;
	}
	if (devices == 0)
		get_cl_error("OpenCL: No suitable hardware found", err);
	context = clCreateContext(0, *num_devices, devices, NULL, NULL, &err);
	get_cl_error("Creating context", err);
	return (context);
}

void		print_cl_infos(cl_context context)
{
	cl_device_id		devices[MAX_DEVICE];
	size_t				size;
	int					elements;
	cl_int				err;
	int					i;
	int					speed;
	char				vendor_name[1024];
	char				device_name[1024];

	i = 0;
	err = clGetContextInfo(context, CL_CONTEXT_DEVICES, sizeof(cl_device_id) * 16,
		&devices, &size);
	get_cl_error("Getting context info", err);
	elements = size / sizeof(cl_device_id);
	while (i < elements)
	{
		err = clGetDeviceInfo(devices[i], CL_DEVICE_VENDOR,
			sizeof(vendor_name), (void *)vendor_name, NULL);
		err |= clGetDeviceInfo(devices[i], CL_DEVICE_NAME,
			sizeof(device_name), (void *)device_name, NULL);
		err |= clGetDeviceInfo(devices[i], CL_DEVICE_MAX_CLOCK_FREQUENCY,
			sizeof(speed), &speed, NULL);
		get_cl_error("Getting device info", err);
		printf("Loaded: %s %s %dmHz\n", vendor_name, device_name, speed);
		i++;
	}
}

void		get_cl_error(char *debug, cl_int err)
{
	ft_putstr_fd(debug, 2);
	ft_putstr_fd("\033[31m:\t", 2);
	ft_putstr_fd(g_cl_errors[-err -1], 2);
    ft_putstr_fd("\033[0m", 2);
    if (err)
    	exit(EXIT_FAILURE);
    else
    	ft_putstr_fd("\033[32mOK!\033[0m\n", 2);
}
