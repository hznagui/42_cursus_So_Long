/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:59:26 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/17 17:42:19 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*ft_number(int n, char *i, int p, int j)
{
	i[p] = '\0';
	while (p-- > 0)
	{
		if (j == 1 && p == 0)
			i[p] = '-';
		else
		{
			i[p] = n % 10 + '0';
			n /= 10;
		}
	}
	return (i);
}

static int	ft_neg(int *n, int *p)
{
	if (*n < 0)
	{
		*p = 1;
		*n *= -1;
	}
	return (0);
}

char	*ft_itoa(int n)
{
	int		p;
	int		u;
	int		j;
	char	*i;

	p = 0;
	j = 0;
	u = n;
	if (!u)
		p = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_neg(&n, &j);
	while (u != 0)
	{
		p++;
		u /= 10;
	}
	i = malloc((p + 1 + j) * sizeof(char));
	if (!i)
		return (0);
	return (ft_number(n, i, p + j, j));
}
/*----------------------------------------------------------------*/

void	skip_nl(t_alldata *a)
{
	int	m;

	m = 1;
	while (a->str[a->z])
	{
		if (a->str[a->z] != '\n')
			m = 0;
		else if (a->str[a->z] == '\n' && m == 1)
			ft_abort(2);
		else if (a->str[a->z] == '\n' && a->str[a->z + 1] == '\n')
			ft_abort(2);
		else if (a->str[a->z] == '\n' && a->str[a->z + 1] == '\0')
			ft_abort(2);
		a->z++;
	}
}
/*----------------------------------------------------------------*/

int	ft_close(void *a)
{
	(void)a;
	exit(0);
}
