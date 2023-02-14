/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:04:54 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/14 14:19:59 by hznagui          ###   ########.fr       */
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
				return (1);
			h++;
		}
		i++;
	}
	return (0);
}
