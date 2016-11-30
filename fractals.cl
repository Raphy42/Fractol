/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.cl                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 00:52:08 by rdantzer          #+#    #+#             */
/*   Updated: 2015/05/04 18:02:39 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma OPENCL EXTENSION cl_khr_fp64 : enable
#pragma OPENCL EXTENSION cl_khr_byte_addressable_store : enable

int index(int x, int y, int width) {
	return width * y + x;
}

double mapX(double x) {
	return x * 3.25 - 2;
}

double mapY(double y) {
	return y * 2.5 - 1.25;
}

__kernel void mandelbrot(__global int *out,
	double max_i, double min_r, double scale_r, double scale_i)
{
	int x_dim = get_global_id(0);
	int y_dim = get_global_id(1);
	size_t width = get_global_size(0);
	size_t height = get_global_size(1);
	int idx = index(x_dim, y_dim, width);
  	double c_i = max_i - y_dim * scale_i;
  	double c_r = min_r + x_dim * scale_r;
	double x = 0.0;
	double y = 0.0;

	int iteration = 0;
	int max_iteration = 5000;
	while(x * x + y * y <= 4 && iteration < max_iteration) {
		double xtemp = x * x - y * y + c_r;
		y = 2 * x * y + c_i;
		x = xtemp;
		iteration++;
	}
	if(iteration == max_iteration)
	{
		out[idx] = 0;
	}
	else
	{
		out[idx] = iteration;
	}
}
