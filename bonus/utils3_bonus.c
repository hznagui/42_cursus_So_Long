/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:28 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/17 18:21:22 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_win2(t_alldata *a)
{
	if (a->taible[a->i][a->h] == 'C')
		mlx_put_image_to_window(a->mlx, a->win, a->col, a->width * a->h,
			a->height * a->i);
	else if (a->taible[a->i][a->h] == '0')
		mlx_put_image_to_window(a->mlx, a->win, a->grn, a->width * a->h,
			a->height * a->i);
	else if (a->taible[a->i][a->h] == 'E')
	{
		if (!find_meat(a->taible))
			mlx_put_image_to_window(a->mlx, a->win, a->dor, a->width * a->h,
				a->height * a->i);
		else
			mlx_put_image_to_window(a->mlx, a->win, a->opndor, a->width * a->h,
				a->height * a->i);
	}
	a->nbr = ft_itoa(a->n);
	if (!a->nbr)
		ft_abort(1);
	mlx_string_put(a->mlx, a->win, 0, 0, 0xFFFFFF, "the moves :  ");
	mlx_string_put(a->mlx, a->win, 120, 0, 0xFFFFFF, a->nbr);
	if (a->nbr)
	{
		free(a->nbr);
		a->nbr = NULL;
	}
}
/*----------------------------------------------------------------*/

void	fill_win(t_alldata *a)
{
	a->i = 0;
	a->h = 0;
	while ((a->taible)[a->i])
	{
		a->h = 0;
		while (a->taible[a->i][a->h])
		{
			if (a->taible[a->i][a->h] == '1')
				mlx_put_image_to_window(a->mlx, a->win, a->wall, a->width
					* a->h, a->height * a->i);
			else if (a->taible[a->i][a->h] == 'P')
			{
				if (a->d == 1)
					mlx_put_image_to_window(a->mlx, a->win, a->ply2, a->width
						* a->h, a->height * a->i);
				else
					mlx_put_image_to_window(a->mlx, a->win, a->ply, a->width
						* a->h, a->height * a->i);
			}
			else
				fill_win2(a);
			a->h++;
		}
		a->i++;
	}
}
/*----------------------------------------------------------------*/

void	ft_check(t_alldata *a)
{
	while (a->taible[a->d])
		a->d++;
	check_size(a, 0, 0);
	check_nb(a, 0, 0, 0);
	find_player(a);
	find_path(a->i, a->h, a);
	if (!find_meat(a->taible2) || !find_exit(a->taible2))
		ft_abort(3);
}
/*----------------------------------------------------------------*/

void	check_name(char *h)
{
	int	y;

	y = ft_strlen(h, '\0');
	if (h[y - 1] != 'r')
		ft_abort(2);
	if (h[y - 2] != 'e')
		ft_abort(2);
	if (h[y - 3] != 'b')
		ft_abort(2);
	if (h[y - 4] != '.')
		ft_abort(2);
}
