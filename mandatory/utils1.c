/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:41:05 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/17 18:09:08 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}
/*----------------------------------------------------------------*/

int	move(int keycode, t_alldata *a)
{
	find_player(a);
	if (keycode == 53)
		exit(0);
	else if (((keycode == 0) || (keycode == 123)) && (a->taible[a->i][a->h
			- 1] != '1') && (a->taible[a->i][a->h - 1] != 'E'))
		return (a->taible[a->i][a->h] = '0', a->taible[a->i][a->h - 1] = 'P',
			a->d = 1, ft_putnbr(a->n++), ft_putchar('\n'), fill_win(a), 0);
	else if (((keycode == 2) || (keycode == 124)) && (a->taible[a->i][a->h
			+ 1] != '1') && (a->taible[a->i][a->h + 1] != 'E'))
		return (a->taible[a->i][a->h] = '0', a->taible[a->i][a->h + 1] = 'P',
			a->d = 0, ft_putnbr(a->n++), ft_putchar('\n'), fill_win(a), 0);
	else if (((keycode == 13) || (keycode == 126)) && (a->taible[a->i
				- 1][a->h] != '1') && (a->taible[a->i - 1][a->h] != 'E'))
		return (a->taible[a->i][a->h] = '0', a->taible[a->i - 1][a->h] = 'P',
			ft_putnbr(a->n++), ft_putchar('\n'), fill_win(a), 0);
	else if (((keycode == 1) || (keycode == 125)) && (a->taible[a->i
				+ 1][a->h] != '1') && (a->taible[a->i + 1][a->h] != 'E'))
		return (a->taible[a->i][a->h] = '0', a->taible[a->i + 1][a->h] = 'P',
			ft_putnbr(a->n++), ft_putchar('\n'), fill_win(a), 0);
	else
		move2(keycode, a);
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
}
/*----------------------------------------------------------------*/

void	ft_images(t_alldata *a)
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
	images2(a);
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
