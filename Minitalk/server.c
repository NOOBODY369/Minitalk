/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobody369 <noobody369@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:45:23 by skarem            #+#    #+#             */
/*   Updated: 2022/10/20 17:11:32 by noobody369       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signal, siginfo_t *info, void *nothing)
{
	static int	client_pid;
	static int	i;
	static int	c;

	(void) nothing;
	if (client_pid != info->si_pid && i != 0)
	{
		i = 0;
		c = 0;
	}
	c = c << 1 | (signal - 30);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	client_pid = info->si_pid;
}

int	main()
{
	struct sigaction	sa;

	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGPWR, &sa, NULL);
	sigaction(SIGSYS, &sa, NULL);
	ft_putstr("PID :\t");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
}
