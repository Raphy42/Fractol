/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 08:12:55 by igomez            #+#    #+#             */
/*   Updated: 2015/04/29 22:15:20 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static int	pf_putbase(int fd, unsigned int n, int b, int *count)
{
	if (n < (unsigned int)b)
	{
		n += (n < 10) ? '0' : 'a' - 10;
		*count += write(fd, &n, 1);
	}
	else
	{
		pf_putbase(fd, n / b, b, count);
		pf_putbase(fd, n % b, b, count);
	}
	return (*count);
}

static int	pf_putnbr(int fd, int n, int *count)
{
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		*count += write(fd, "-", 1);
		n = -n;
	}
	if (n < 10)
	{
		n += '0';
		*count += 1;
		write(fd, &n, 1);
	}
	else
	{
		pf_putnbr(fd, n / 10, count);
		pf_putnbr(fd, n % 10, count);
	}
	return (*count);
}

static int	pf_putfloat(int fd, double fl, int *count)
{
	int i;

	pf_putnbr(fd, (int)fl, count);
	*count += write(fd, ".", 1);
	fl -= (int)fl;
	i = 0;
	while (i++ < 6)
		fl *= (double)10.0;
	if (fl < 0)
		fl *= -1;
	pf_putnbr(fd, (int)fl, count);
	return (*count);
}

static int	ft_pfprint(int fd, char c, va_list *ap, int *count)
{
	char	*s;
	char	p;
	int		i;

	i = 0;
	if (c == '%')
		return (write(fd, "%", 1));
	else if (c == 'c' && (p = (char)va_arg(*ap, int)))
		return (write(fd, &p, 1));
	else if (c == 's' && (s = (char *)va_arg(*ap, char const *)))
		while (s && *(s + i))
			write(fd, s + i++, 1);
	else if (c == 'd' || c == 'i')
		return (pf_putnbr(fd, (int)va_arg(*ap, int), count));
	else if (c == 'o')
		return (pf_putbase(fd, (unsigned int)va_arg(*ap, int), 8, count));
	else if (c == 'u')
		return (pf_putbase(fd, (unsigned int)va_arg(*ap, int), 10, count));
	else if (c == 'b')
		return (pf_putbase(fd, (unsigned int)va_arg(*ap, int), 2, count));
	else if (c == 'x')
		return (pf_putbase(fd, (unsigned int)va_arg(*ap, int), 16, count));
	else if (c == 'f')
		return (pf_putfloat(fd, (double)va_arg(*ap, double), count));
	return (i - (c == 's'));
}

int			ft_fprintf(int fd, char const *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	if (!format)
		return (0);
	va_start(ap, format);
	while (*format != 0)
	{
		count = 0;
		if (*format++ == '%')
			i += ft_pfprint(fd, *format++, &ap, &count);
		else
			i += write(fd, format - 1, 1);
	}
	va_end(ap);
	return (i + (i != 0));
}
