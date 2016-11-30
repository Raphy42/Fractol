/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 23:11:00 by rdantzer          #+#    #+#             */
/*   Updated: 2015/05/05 02:19:30 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fractol.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <sys/stat.h>

extern char	**environ;

int				file_rights(char *binary)
{
	struct stat	stats;

	if (lstat(binary, &stats) < 0)
		return (ft_fprintf(2, "can't access buddhabrot\n"));
	if (!(stats.st_mode & (1 << 6)))
		return (ft_fprintf(2, "no rights on buddhabrot\n"));
	if (S_ISDIR(stats.st_mode))
		return (ft_fprintf(2, "is a directory, seriously ?\n"));
	return (0);
}

char **			create_argv(t_fract *f)
{
	char		**new;

	new = (char **)malloc(sizeof(char *) * 3);
	new[0] = ft_strdup("fractol");
	new[1] = ft_itoa(f->type);
	new[2] = NULL;
	return (new);
}

void			launch_fractal(t_fract *f, int is_budda)
{
	pid_t		pid;
	char		**argv;

	argv = create_argv(f);
	if (is_budda)
		if (file_rights("buddhabrot"))
			return ;
	if ((pid = fork()) < 0)
		ft_putendl_fd("unable to create process", 2);
	else if (pid == 0)
	{
		execve(is_budda ? "buddhabrot" : "fractol" , is_budda ? NULL : argv, environ);
		ft_putendl_fd("cannot execute binary", 2);
	}
	else
	{
		ft_arraydel(argv);
		ft_fprintf(2, "New \033[32m%s\033[0m window was created\n", is_budda ?
			"buddhabrot" : "fractal");
	}
}
