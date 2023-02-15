/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:04:54 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/15 11:46:08 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_alldata *a)
{

	a->i = 0;
	a->h = 0;
	while ((a->taible)[a->i])
	{
		a->h = 0;
		while (a->taible[a->i][a->h])
		{
			if (a->taible[a->i][a->h] == 'P')
				return ;
			a->h++;
		}
		a->i++;
	}
}

int	find_meat(char **a)
{
	int	i;
	int	h;

	i = 0;
	h = 0;
	while ((a)[i])
	{
		h = 0;
		while (a[i][h])
		{
			if (a[i][h] == 'C')
				return (0);
			h++;
		}
		i++;
	}
	return (1);
}

void	ft_abort(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}