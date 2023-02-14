/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:46:15 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/14 18:56:58 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				mlx_put_image_to_window(a->mlx, a->win, a->wall, a->width * a->h, a->height * a->i);
			else if (a->taible[a->i][a->h] == '0')
				mlx_put_image_to_window(a->mlx, a->win, a->grn, a->width * a->h,a->height * a->i);
			else if (a->taible[a->i][a->h] == 'P')
			{
				if (a->d == 0)
					mlx_put_image_to_window(a->mlx, a->win, a->ply2, a->width * a->h, a->height * a->i);
				else
					mlx_put_image_to_window(a->mlx, a->win, a->ply, a->width * a->h, a->height * a->i);
			}
			else if (a->taible[a->i][a->h] == 'C')
				mlx_put_image_to_window(a->mlx, a->win, a->col, a->width * a->h, a->height * a->i);
			else if (a->taible[a->i][a->h] == 'E')
			{
				if (find_meat(a->taible))
					mlx_put_image_to_window(a->mlx, a->win, a->dor, a->width
							* a->h, a->height * a->i);
				else
					mlx_put_image_to_window(a->mlx, a->win, a->opndor, a->width
							* a->h, a->height * a->i);
			}
			else if (a->taible[a->i][a->h] == 'A')
				mlx_put_image_to_window(a->mlx, a->win, a->enemy,  a->width * a->h , a->height * a->i);
			// printf("ha ana \n");
			a->h++;
		}
		a->i++;
	}
}


int	move(int keycode, t_alldata *a)
{
	find_player(a);
	if (keycode == 53)
		exit(0);
	else if (((keycode == 0) || (keycode == 123)) && (a->taible[a->i][a->h
				- 1] != '1'))
	{
		a->taible[a->i][a->h] = '0';
		a->taible[a->i][a->h - 1] = 'P';
		a->d = 0;
	}
	else if (((keycode == 2) || (keycode == 124)) && (a->taible[a->i][a->h
				+ 1] != '1'))
	{
		a->taible[a->i][a->h] = '0';
		a->taible[a->i][a->h + 1] = 'P';
		a->d = 1;
	}
	else if (((keycode == 13) || (keycode == 126)) && (a->taible[a->i
				- 1][a->h] != '1'))
	{
		a->taible[a->i][a->h] = '0';
		a->taible[a->i - 1][a->h] = 'P';
	}
	else if (((keycode == 1) || (keycode == 125)) && (a->taible[a->i
				+ 1][a->h] != '1'))
	{
		a->taible[a->i][a->h] = '0';
		a->taible[a->i + 1][a->h] = 'P';
	}
	fill_win(a);
	return (0);
}

int	ft_close(void *a)
{
	(void)a;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_alldata	a;

	if (argc == 2)
	{
		a.i = 0;
		a.str = reading_map(argv[1]);
		a.mlx = mlx_init();
		a.taible = ft_split(a.str, '\n');
		while (a.taible[a.i])
			a.i++;
		a.grn = mlx_xpm_file_to_image(a.mlx, "../utils/realwall.xpm", &a.width,
				&a.height);
		a.col = mlx_xpm_file_to_image(a.mlx, "../utils/l7am.xpm", &a.width,
				&a.height);
		a.dor = mlx_xpm_file_to_image(a.mlx, "../utils/bab.xpm", &a.width,
				&a.height);
		a.enemy = mlx_xpm_file_to_image(a.mlx, "../utils/enemy.xpm", &a.width,
				&a.height);
		a.wall = mlx_xpm_file_to_image(a.mlx, "../utils/wall.xpm", &a.width,
				&a.height);
		a.ply = mlx_xpm_file_to_image(a.mlx, "../utils/playerfinish.xpm",
				&a.width, &a.height);
		a.opndor = mlx_xpm_file_to_image(a.mlx, "../utils/opendoor.xpm",
				&a.width, &a.height);
		a.ply2 = mlx_xpm_file_to_image(a.mlx, "../utils/playerme9lob.xpm",
				&a.width, &a.height);
		a.win = mlx_new_window(a.mlx, ft_strlen(a.taible[1], '\0') * a.width,
				a.i * a.height, "So_long");
		fill_win(&a);
		// printf("%d\n",a.i);
		mlx_hook(a.win, 2, 0, move, &a);
		mlx_hook(a.win, 17, 0, ft_close, &a);
		mlx_loop(a.mlx);
	}
	else
		ft_abort();
}
