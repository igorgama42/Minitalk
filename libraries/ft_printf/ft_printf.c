/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:42:50 by igama             #+#    #+#             */
/*   Updated: 2023/11/28 08:58:00 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list arguments)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arguments, int)), 1);
	else if (c == 'i' || c == 'd')
		return (ft_digits(va_arg(arguments, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arguments, char *)));
	else if (c == 'u')
		return (ft_digits_uns(va_arg(arguments, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'), 1);
	else if (c == 'p')
		return (ft_digits_base(va_arg(arguments, unsigned long int)));
	else if (c == 'x')
		return (ft_digits_x(va_arg(arguments, unsigned int)));
	else if (c == 'X')
		return (ft_digits_cx(va_arg(arguments, unsigned int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		arguments;
	int			i;

	i = 0;
	va_start(arguments, str);
	while (*str)
	{
		while (*str == '%')
		{
			str++;
			i += ft_format(*str, arguments);
			str++;
		}
		if (*str != '\0')
		{
			ft_putchar(*str);
			str++;
			i++;
		}
	}
	return (i);
}
