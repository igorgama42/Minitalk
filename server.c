/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:18:49 by igama             #+#    #+#             */
/*   Updated: 2024/05/04 20:11:49 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "./libraries/ft_printf/ft_printf.h"

int		ft_printf(const char *str, ...);
void	bit_handler(int sig);
void	ft_putchar(char c);

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	action.sa_handler = &bit_handler;
	ft_printf("pid: %d\n", pid);
	while (42)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}

void	bit_handler(int sig)
{
	static int	c;
	static int	bit;

	if (!bit)
		bit = 128;
	if (sig == SIGUSR1)
		c = c + bit;
	bit = bit / 2;
	if (!bit)
	{
		write(1, &c, 1);
		c = 0x00;
	}
}
