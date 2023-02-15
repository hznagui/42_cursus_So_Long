/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:10:37 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/15 15:25:43 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_path(int i, int h,t_alldata *a)
{
    if (a->taible2[i][h] == '1' || a->taible2[i][h] == '4' || h >= (int)ft_strlen(a->taible2[0],'\0') || i >= a->d|| a->taible2[i][h] == 'A')
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
void ft_check(t_alldata *a)
{
    while (a->taible[a->d])
		a->d++;
    find_player(a);
    find_path(a->i,a->h,a);
    if (!find_meat(a->taible2) || !find_exit(a->taible2))
    {
        write(2,"error : check the path\n",24);
        exit(1);
    }
    // int l=0;
    // while (a->taible2[l])
    // {
    //     printf("%s\n",a->taible2[l]);
    //     l++;
    // }

    
}