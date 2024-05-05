/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:18:49 by igama             #+#    #+#             */
/*   Updated: 2024/05/04 20:15:55 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "./libraries/ft_printf/ft_printf.h"

void	ft_send_bit(char c, int pid);
int		ft_atoi(const char *nptr);

int	main(int argc, char **argv)
{
	int	i;
	int	pid_receiver;

	if (argc == 1)
		return (0);
	i = 0;
	pid_receiver = ft_atoi(argv[1]);
	if (argc < 3)
	{
		ft_printf("INPUT ERROR: TRY AGAIN");
		return (0);
	}
	while (argv[2][i])
	{
		ft_send_bit(argv[2][i], pid_receiver);
		i++;
		usleep(420);
	}
	return (0);
}

void	ft_send_bit(char c, int pid)
{
	int	bit;

	bit = 8;
	while (bit)
	{
		bit--;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(420);
	}
}

int	ft_atoi(const char *nptr)
{
	int	ct;
	int	minus;
	int	nbr;

	ct = 0;
	minus = 1;
	nbr = 0;
	while (nptr[ct] == ' ' || (nptr[ct] >= 9 && nptr[ct] <= 13))
		ct++;
	if (nptr[ct] == '-')
	{
		minus *= -1;
		ct++;
	}
	else if (nptr[ct] == '+')
		ct++;
	while (nptr[ct] >= '0' && nptr[ct] <= '9')
	{
		nbr *= 10;
		nbr += nptr[ct] - '0';
		ct++;
	}
	return (nbr * minus);
}
