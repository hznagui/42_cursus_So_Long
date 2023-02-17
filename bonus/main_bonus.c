/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:46:15 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/17 15:35:58 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move3(int keycode, t_alldata *a)
{
	if (((keycode == 0) || (keycode == 123)) && (a->taible[a->i][a->h
			- 1] == 'A'))
		return (a->n++, write(1, "YOU LOSE!\n", 11), exit(0));
	else if (((keycode == 2) || (keycode == 124)) && (a->taible[a->i][a->h
			+ 1] == 'A'))
		return (a->n++, write(1, "YOU LOSE!\n", 11), exit(0));
	else if (((keycode == 13) || (keycode == 126)) && (a->taible[a->i
				- 1][a->h] == 'A'))
		return (a->n++, write(1, "YOU LOSE!\n", 11), exit(0));
	else if (((keycode == 1) || (keycode == 125)) && (a->taible[a->i
				+ 1][a->h] == 'A'))
		return (a->n++, write(1, "YOU LOSE!\n", 11), exit(0));
}

void	move2(int keycode, t_alldata *a)
{
	if (((keycode == 0) || (keycode == 123)) && (a->taible[a->i][a->h
			- 1] == 'E') && find_meat(a->taible))
		return (a->n++, write(1, "YOU WIN!\n", 10), exit(0));
	else if (((keycode == 2) || (keycode == 124)) && (a->taible[a->i][a->h
			+ 1] == 'E') && find_meat(a->taible))
		return (a->n++, write(1, "YOU WIN!\n", 10), exit(0));
	else if (((keycode == 13) || (keycode == 126)) && (a->taible[a->i
				- 1][a->h] == 'E') && find_meat(a->taible))
		return (a->n++, write(1, "YOU WIN!\n", 10), exit(0));
	else if (((keycode == 1) || (keycode == 125)) && (a->taible[a->i
				+ 1][a->h] == 'E') && find_meat(a->taible))
		return (a->n++, write(1, "YOU WIN!\n", 10), exit(0));
	else if (((keycode == 1) || (keycode == 125)) && (a->taible[a->i
				+ 1][a->h] != '1') && (a->taible[a->i + 1][a->h] != 'E')
			&& (a->taible[a->i + 1][a->h] != 'A'))
		return (a->taible[a->i][a->h] = '0', a->taible[a->i + 1][a->h] = 'P',
			a->n++, fill_win(a));
	else
		move3(keycode, a);
}

int	main(int argc, char **argv)
{
	t_alldata	a;

	if (argc == 2)
	{
		a.d = 0;
		a.n = 0;
		a.z = 0;
		a.str = reading_map(argv[1], NULL, 1);
		skip_nl(&a);
		a.mlx = mlx_init();
		a.taible = ft_split(a.str, '\n');
		a.taible2 = ft_split(a.str, '\n');
		ft_check(&a);
		images(&a);
		mlx_loop_hook(a.mlx, &anime, &a);
		fill_win(&a);
		mlx_hook(a.win, 2, 0, move, &a);
		mlx_hook(a.win, 17, 0, ft_close, &a);
		mlx_loop(a.mlx);
	}
	else
		ft_abort(7);
}
