/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobody369 <noobody369@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:08:24 by skarem            #+#    #+#             */
/*   Updated: 2022/10/18 20:48:32 by noobody369       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, (c >> i & 1) + +);
		usleep(500);
		i--;
	}
}

int	check_pid(char *str)
{
	int	pid;

	pid = ft_atoi(str);
	if (pid < 0)
		return (-1);
	return (pid);
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(2, "\033[0;32mServer: message received\n", 33);
	}
	exit(0);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*string;
	int		i;

	i = 0;
	if (ac != 3)
	{
		write(2, "\033[0;31mnot enough arguments\n", 29);
		return (0);
	}
	string = av[2];
	pid = check_pid(av[1]);
	if (pid <= 0)
	{
		write(2, "\033[0;31m!INCORRECT PID!\n", 24);
		return (0);
	}
	signal(SIGUSR1, sig_handler);
	while (string[i])
	{
		send_char(string[i], pid);
		i++;
	}
	send_char(0, pid);
}
