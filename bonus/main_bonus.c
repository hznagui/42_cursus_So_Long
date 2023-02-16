/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:46:15 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/16 15:26:58 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_win2(t_alldata *a)
{
	if (a->taible[a->i][a->h] == 'C')
		mlx_put_image_to_window(a->mlx, a->win, a->col, a->width * a->h,
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
	else if (a->taible[a->i][a->h] == 'A')
		mlx_put_image_to_window(a->mlx, a->win, a->enemy, a->width * a->h,
				a->height * a->i);
}
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
			else if (a->taible[a->i][a->h] == '0')
				mlx_put_image_to_window(a->mlx, a->win, a->grn, a->width * a->h,
						a->height * a->i);
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

void	move3(int keycode, t_alldata *a)
{
	if (((keycode == 0) || (keycode == 123)) && (a->taible[a->i][a->h
			- 1] == 'A'))
		return (ft_putnbr(a->n++), ft_putchar('\n'), write(1, "YOU LOSE!\n",
				11), exit(0));
	else if (((keycode == 2) || (keycode == 124)) && (a->taible[a->i][a->h
				+ 1] == 'A'))
		return (ft_putnbr(a->n++), ft_putchar('\n'), write(1, "YOU LOSE!\n",
				11), exit(0));
	else if (((keycode == 13) || (keycode == 126)) && (a->taible[a->i
				- 1][a->h] == 'A'))
		return (ft_putnbr(a->n++), ft_putchar('\n'), write(1, "YOU LOSE!\n",
				11), exit(0));
	else if (((keycode == 1) || (keycode == 125)) && (a->taible[a->i
				+ 1][a->h] == 'A'))
		return (ft_putnbr(a->n++), ft_putchar('\n'), write(1, "YOU LOSE!\n",
				11), exit(0));
}

void	move2(int keycode, t_alldata *a)
{
	if (((keycode == 0) || (keycode == 123)) && (a->taible[a->i][a->h
			- 1] == 'E') && find_meat(a->taible))
		return (ft_putnbr(a->n++), ft_putchar('\n'), write(1, "YOU WIN!\n", 10),
			exit(0));
	else if (((keycode == 2) || (keycode == 124)) && (a->taible[a->i][a->h
				+ 1] == 'E') && find_meat(a->taible))
		return (ft_putnbr(a->n++), ft_putchar('\n'), write(1, "YOU WIN!\n", 10),
			exit(0));
	else if (((keycode == 13) || (keycode == 126)) && (a->taible[a->i
				- 1][a->h] == 'E') && find_meat(a->taible))
		return (ft_putnbr(a->n++), ft_putchar('\n'), write(1, "YOU WIN!\n", 10),
			exit(0));
	else if (((keycode == 1) || (keycode == 125)) && (a->taible[a->i
				+ 1][a->h] == 'E') && find_meat(a->taible))
		return (ft_putnbr(a->n++), ft_putchar('\n'), write(1, "YOU WIN!\n", 10),
			exit(0));
	else
		move3(keycode, a);
}

int	move(int keycode, t_alldata *a)
{
	find_player(a);
	if (keycode == 53)
		exit(0);
	else if (((keycode == 0) || (keycode == 123)) && (a->taible[a->i][a->h
				- 1] != '1') && (a->taible[a->i][a->h - 1] != 'E')
			&& (a->taible[a->i][a->h - 1] != 'A'))
		return (a->taible[a->i][a->h] = '0', a->taible[a->i][a->h - 1] = 'P',
			a->d = 1, ft_putnbr(a->n++), ft_putchar('\n'), fill_win(a), 0);
	else if (((keycode == 2) || (keycode == 124)) && (a->taible[a->i][a->h
				+ 1] != '1') && (a->taible[a->i][a->h + 1] != 'E')
			&& (a->taible[a->i][a->h + 1] != 'A'))
		return (a->taible[a->i][a->h] = '0', a->taible[a->i][a->h + 1] = 'P',
			a->d = 0, ft_putnbr(a->n++), ft_putchar('\n'), fill_win(a), 0);
	else if (((keycode == 13) || (keycode == 126)) && (a->taible[a->i
				- 1][a->h] != '1') && (a->taible[a->i - 1][a->h] != 'E')
			&& (a->taible[a->i - 1][a->h] != 'A'))
		return (a->taible[a->i][a->h] = '0', a->taible[a->i - 1][a->h] = 'P',
			ft_putnbr(a->n++), ft_putchar('\n'), fill_win(a), 0);
	else if (((keycode == 1) || (keycode == 125)) && (a->taible[a->i
				+ 1][a->h] != '1') && (a->taible[a->i + 1][a->h] != 'E')
			&& (a->taible[a->i + 1][a->h] != 'A'))
		return (a->taible[a->i][a->h] = '0', a->taible[a->i + 1][a->h] = 'P',
			ft_putnbr(a->n++), ft_putchar('\n'), fill_win(a), 0);
	else
		move2(keycode, a);
	return (0);
}

int	ft_close(void *a)
{
	(void)a;
	exit(0);
}
void	skip_nl(t_alldata *a)
{
	int	u;
	int	m;

	while (a->str[a->z])
	{
		u = 0;
		if (a->str[a->z] != '\n')
			m = 1;
		while (a->str[a->z] == '\n' && m == 1)
		{
			u++;
			a->z++;
		}
		if (a->str[a->z] && u > 1)
			ft_abort(2);
		a->z++;
	}
}
void	images2(t_alldata *a){
	a->wall = mlx_xpm_file_to_image(a->mlx, "../utils/wall.xpm", &a->width,
			&a->height);
	if (!(a->wall) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->ply = mlx_xpm_file_to_image(a->mlx, "../utils/playerfinish.xpm",
			&a->width, &a->height);
	if (!(a->ply) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->opndor = mlx_xpm_file_to_image(a->mlx, "../utils/opendoor.xpm",
			&a->width, &a->height);
	if (!(a->opndor) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->ply2 = mlx_xpm_file_to_image(a->mlx, "../utils/playerme9lob.xpm",
			&a->width, &a->height);
	if (!(a->ply2) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->win = mlx_new_window(a->mlx, ft_strlen(a->taible[1], '\0') * a->width,
			a->d * a->height, "So_long");
	if (!(a->win))
		ft_abort(10);
}
void	images(t_alldata *a)
{
	a->grn = mlx_xpm_file_to_image(a->mlx, "../utils/realwall.xpm", &a->width,
			&a->height);
	if (!(a->grn) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->col = mlx_xpm_file_to_image(a->mlx, "../utils/l7am.xpm", &a->width,
			&a->height);
	if (!(a->col) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->dor = mlx_xpm_file_to_image(a->mlx, "../utils/bab.xpm", &a->width,
			&a->height);
	if (!(a->dor) || a->width != 50 || a->height != 50)
		ft_abort(10);
	a->enemy = mlx_xpm_file_to_image(a->mlx, "../utils/enemy.xpm", &a->width,
			&a->height);
	if (!(a->enemy) || a->width != 50 || a->height != 50)
		ft_abort(10);
	images2(a);
}

int	main(int argc, char **argv)
{
	t_alldata	a;

	if (argc == 2)
	{
		a.d = 0;
		a.n = 0;
		a.z = 0;
		a.str = reading_map(argv[1]);
		skip_nl(&a);
		a.mlx = mlx_init();
		a.taible = ft_split(a.str, '\n');
		a.taible2 = ft_split(a.str, '\n');
		ft_check(&a);
		images(&a);
		fill_win(&a);
		mlx_hook(a.win, 2, 0, move, &a);
		mlx_hook(a.win, 17, 0, ft_close, &a);
		mlx_loop(a.mlx);
	}
	else
		ft_abort(7);
}
