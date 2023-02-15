/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:10:37 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/15 17:17:36 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_path(int i, int h,t_alldata *a)
{
    if (a->taible2[i][h] == '1' || a->taible2[i][h] == '4' || h >= (int)ft_strlen(a->taible2[0],'\0') || i >= a->d || a->taible2[i][h] == 'A')
        return;
    else if(a->taible2[i][h] == 'E')
        a->taible2[i][h] = '6';
    else if (a->taible2[i][h] == '0' || a->taible2[i][h] == 'C' || a->taible2[i][h] == 'P')
    {
        a->taible2[i][h] = '4';
        find_path(i+1,h,a);
        find_path(i-1,h,a);
        find_path(i,h+1,a);
        find_path(i,h-1,a);
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
void check_nb(t_alldata *a,int P,int C,int E)
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
			a->h++;
		}
		a->i++;
	}
    if (P != 1 || C == 0 || E != 1)
    {
        write(2,"Error : check the numbers\n",27);
        exit(1);
    }
}

void ft_check(t_alldata *a)
{
    check_nb(a,0,0,0);
    while (a->taible[a->d])
		a->d++;
    find_player(a);
    find_path(a->i,a->h,a);
    if (!find_meat(a->taible2) || !find_exit(a->taible2))
    {
        write(2,"Error : check the path\n",24);
        exit(1);
    }
}