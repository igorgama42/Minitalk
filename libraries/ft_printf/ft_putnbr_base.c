/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 02:05:44 by igama             #+#    #+#             */
/*   Updated: 2023/11/28 08:58:42 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long int n)
{
	const char	array[16] = {"0123456789abcdef"};

	if (n > 15)
	{
		ft_putnbr_base(n / 16);
		ft_putnbr_base(n % 16);
	}
	if (n <= 15)
		ft_putchar(array[n]);
}

unsigned long int	ft_digits_base(unsigned long int n)
{
	int	n_digits;

	if (n == 0)
		return (write(1, "(nil)", 5));
	n_digits = 2;
	write(1, "0x", 2);
	ft_putnbr_base(n);
	while (n > 0)
	{
		n /= 16;
		n_digits++;
	}
	return (n_digits);
}
