/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarem <skarem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:41:17 by skarem            #+#    #+#             */
/*   Updated: 2022/04/24 11:24:38 by skarem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sig_handler(int signal, siginfo_t *info, void *noth)
{
	static int	client_pid;
	static char	ls;
	static int	i;
	static int	c;

	(void) noth;
	if (client_pid != info->si_pid && (ls >> 7) & 1)
		ft_putchar(8);
	if (client_pid != info->si_pid && i != 0)
	{
		i = 0;
		c = 0;
	}
	c = c << 1 | (signal - 30);
	i++;
	if (i == 8)
	{
		if (c == 0)
			kill (info->si_pid, SIGUSR1);
		ft_putchar(c);
		ls = c;
		c = 0;
		i = 0;
	}
	client_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("PID :\t");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
}
