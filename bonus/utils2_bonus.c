/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:12:35 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/17 17:46:24 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_anime(t_alldata *a)
{
	if (a->taible[a->i][a->h] == 'A' && a->z == 0)
	{
		mlx_put_image_to_window(a->mlx, a->win, a->enemy1, a->width * a->h,
			a->height * a->i);
		a->z = 1;
	}
	else if (a->taible[a->i][a->h] == 'A' && a->z == 1)
	{
		mlx_put_image_to_window(a->mlx, a->win, a->enemy2, a->width * a->h,
			a->height * a->i);
		a->z = 2;
	}
	else if (a->taible[a->i][a->h] == 'A' && a->z == 2)
	{
		mlx_put_image_to_window(a->mlx, a->win, a->enemy3, a->width * a->h,
			a->height * a->i);
		a->z = 5;
	}
	else if (a->taible[a->i][a->h] == 'A')
	{
		mlx_put_image_to_window(a->mlx, a->win, a->enemy4, a->width * a->h,
			a->height * a->i);
		a->z = 0;
	}
}
/*----------------------------------------------------------------*/

int	anime(t_alldata *a)
{
	static int	l;

	a->i = 0;
	a->h = 0;
	if (l > 1500)
	{
		while ((a->taible)[a->i])
		{
			a->h = 0;
			while (a->taible[a->i][a->h])
			{
				fill_anime(a);
				a->h++;
			}
			a->i++;
		}
		l = 0;
	}
	else
		l++;
	return (0);
}
/*----------------------------------------------------------------*/

void	images2(t_alldata *a)
{
	a->wall = mlx_xpm_file_to_image(a->mlx, "./textures/wall.xpm", &a->width,
			&a->height);
	if (!(a->wall) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->ply = mlx_xpm_file_to_image(a->mlx, "./textures/playerfinish.xpm",
			&a->width, &a->height);
	if (!(a->ply) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->opndor = mlx_xpm_file_to_image(a->mlx, "./textures/opendoor.xpm",
			&a->width, &a->height);
	if (!(a->opndor) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->ply2 = mlx_xpm_file_to_image(a->mlx, "./textures/playerme9lob.xpm",
			&a->width, &a->height);
	if (!(a->ply2) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->win = mlx_new_window(a->mlx, ft_strlen(a->taible[1], '\0') * a->width,
			a->d * a->height, "So_long");
	if (!(a->win))
		ft_abort(10);
	a->enemy4 = mlx_xpm_file_to_image(a->mlx, "./textures/fire4.xpm", &a->width,
			&a->height);
	if (!(a->enemy4) || a->width != 50 || a->height != 50)
		ft_abort(10);
}

/*----------------------------------------------------------------*/

void	images(t_alldata *a)
{
	a->grn = mlx_xpm_file_to_image(a->mlx, "./textures/realwall.xpm", &a->width,
			&a->height);
	if (!(a->grn) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->col = mlx_xpm_file_to_image(a->mlx, "./textures/l7am.xpm", &a->width,
			&a->height);
	if (!(a->col) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->dor = mlx_xpm_file_to_image(a->mlx, "./textures/bab.xpm", &a->width,
			&a->height);
	if (!(a->dor) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->enemy1 = mlx_xpm_file_to_image(a->mlx, "./textures/fire.xpm", &a->width,
			&a->height);
	if (!(a->enemy1) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->enemy2 = mlx_xpm_file_to_image(a->mlx, "./textures/fire2.xpm", &a->width,
			&a->height);
	if (!(a->enemy2) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->enemy3 = mlx_xpm_file_to_image(a->mlx, "./textures/fire3.xpm", &a->width,
			&a->height);
	if (!(a->enemy3) || a->width != 50 || a->height != 50)
		ft_abort(10);
	images2(a);
}
/*----------------------------------------------------------------*/

int	move(int keycode, t_alldata *a)
{
	find_player(a);
	if (keycode == 53)
		exit(0);
	else if (((keycode == 0) || (keycode == 123)) && (a->taible[a->i][a->h
			- 1] != '1') && (a->taible[a->i][a->h - 1] != 'E')
			&& (a->taible[a->i][a->h - 1] != 'A'))
		return (a->taible[a->i][a->h] = '0', a->taible[a->i][a->h - 1] = 'P',
			a->d = 1, a->n++, fill_win(a), 0);
	else if (((keycode == 2) || (keycode == 124)) && (a->taible[a->i][a->h
			+ 1] != '1') && (a->taible[a->i][a->h + 1] != 'E')
			&& (a->taible[a->i][a->h + 1] != 'A'))
		return (a->taible[a->i][a->h] = '0', a->taible[a->i][a->h + 1] = 'P',
			a->d = 0, a->n++, fill_win(a), 0);
	else if (((keycode == 13) || (keycode == 126)) && (a->taible[a->i
				- 1][a->h] != '1') && (a->taible[a->i - 1][a->h] != 'E')
			&& (a->taible[a->i - 1][a->h] != 'A'))
		return (a->taible[a->i][a->h] = '0', a->taible[a->i - 1][a->h] = 'P',
			a->n++, fill_win(a), 0);
	else
		move2(keycode, a);
	return (0);
}
