/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:37:52 by igama             #+#    #+#             */
/*   Updated: 2023/11/28 08:58:50 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_uns(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_uns(n / 10);
		ft_putnbr_uns(n % 10);
	}
	if (n <= 9)
		ft_putchar(n + '0');
}

int	ft_digits_uns(unsigned int n)
{
	int	n_digits;

	n_digits = 0;
	ft_putnbr_uns(n);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		n_digits++;
	}
	return (n_digits);
}
