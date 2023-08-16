/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobody369 <noobody369@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:41:54 by skarem            #+#    #+#             */
/*   Updated: 2022/10/18 21:04:50 by noobody369       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, (c >> i & 1) + SIGPWR);
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

int	main(int argc, char *argv[])
{
	int		pid;
	char	*string;
	int		i;

	i = 0;
	if (argc != 3)
	{
		write(2, "\033[0;31mnot enough arguments\n", 29);
		return (0);
	}	
	string = argv[2];
	pid = check_pid(argv[1]);
	if (pid <= 0)
	{
		write(2, "\033[0;31m!INCORRECT PID!\n", 24);
		return (0);
	}
	while (string[i])
	{
		send_char(string[i], pid);
		i++;
	}
	send_char(0, pid);
}
