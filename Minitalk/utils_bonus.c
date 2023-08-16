/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarem <skarem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:34:29 by skarem            #+#    #+#             */
/*   Updated: 2022/04/24 23:19:29 by skarem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr(int nb)
{
	long	c;

	c = nb;
	if (c < 0)
	{
		c *= -1;
		ft_putchar('-');
	}
	if (c < 10)
	{
		ft_putchar(c + '0');
	}
	else
	{
		ft_putnbr(c / 10);
		ft_putnbr(c % 10);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i])
	{	
		if (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + (str[i] - '0');
				i++;
		}
		else
			return (-1);
	}
	return (sign * (int)nb);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
