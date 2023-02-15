/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:10:37 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/15 19:14:11 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_path(int i, int h, t_alldata *a)
{
	if (a->taible2[i][h] == '1' || a->taible2[i][h] == '4'
		|| h >= (int)ft_strlen(a->taible2[0], '\0') || i >= a->d
		|| a->taible2[i][h] == 'A')
		return ;
	else if (a->taible2[i][h] == 'E')
		a->taible2[i][h] = '6';
	else if (a->taible2[i][h] == '0' || a->taible2[i][h] == 'C'
			|| a->taible2[i][h] == 'P')
	{
		a->taible2[i][h] = '4';
		find_path(i + 1, h, a);
		find_path(i - 1, h, a);
		find_path(i, h + 1, a);
		find_path(i, h - 1, a);
	}
}

int	find_exit(char **a)
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
			if (a[i][h] == 'E')
				return (0);
			h++;
		}
		i++;
	}
	return (1);
}

void	check_nb(t_alldata *a, int P, int C, int E)
{
	a->i = 0;
	while ((a->taible)[a->i])
	{
		a->h = 0;
		while (a->taible[a->i][a->h])
		{
			if (a->taible[a->i][a->h] == 'E')
				E += 1;
			else if (a->taible[a->i][a->h] == 'C')
				C += 1;
			else if (a->taible[a->i][a->h] == 'P')
				P += 1;
            else if (a->taible[a->i][a->h] == '1' && a->taible[a->i][a->h] == '0' && a->taible[a->i][a->h] == 'A')
                ft_abort(5);
			a->h++;
		}
		a->i++;
	}
	if (P != 1 || C == 0 || E != 1)
        ft_abort(4);
}


void check_eadgs(t_alldata *a,int k,int y,int z)
{
    while (a->taible[0][y])
    {
        if (a->taible[0][y++] != '1')
            ft_abort(9);
    }
    while (a->taible[z])
    {
        if (a->taible[z++][0] != '1')
            ft_abort(9);
    }
    while (a->taible[k])
    {
        if (a->taible[k][ft_strlen(a->taible[k],'\0')-1] != '1')
            ft_abort(9);
        k++;
    }
}

void    check_size(t_alldata *a,int k,int y)
{
    int h;
    
    h = a->d - 1;
    if (5 > ft_strlen(a->taible[0],'\0') || a->d < 3 || (int)ft_strlen(a->taible[0],'\0') <= a->d)
        ft_abort(2);
    while (a->taible[k])
    {
        if (ft_strlen(a->taible[0],'\0') != ft_strlen(a->taible[k++],'\0'))
            ft_abort(2);
    }
    while (a->taible[h][y])
    {
        if (a->taible[h][y++] != '1')
            ft_abort(9);
    }
    check_eadgs(a,0,0,0);
}

void	ft_check(t_alldata *a)
{
	while (a->taible[a->d])
		a->d++;
    check_size(a,0,0);
    check_nb(a, 0, 0, 0);
	find_player(a);
	find_path(a->i, a->h, a);
	if (!find_meat(a->taible2) || !find_exit(a->taible2))
	    ft_abort(3);
}
