/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:31:28 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/16 18:33:13 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	c = 0;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			ft_putstr("\nMessage received from PID: ");
			ft_putnbr(info->si_pid);
			write(1, "\n", 1);
		}
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
	{
		ft_putstr("Error: sigaction(SIGUSR1) failed\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &act, NULL) == -1)
	{
		ft_putstr("Error: sigaction(SIGUSR2) failed\n");
		return (1);
	}
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	ft_putstr("\nWaiting for messages...\n");
	while (1)
		pause();
	return (0);
}
