/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:46:15 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/17 18:20:56 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		a.d = 0;
		a.n = 1;
		a.z = 0;
		check_name(argv[1]);
		a.str = reading_map(argv[1], NULL, 1);
		skip_nl(&a);
		a.mlx = mlx_init();
		if (!(a.mlx))
			ft_abort(10);
		a.taible = ft_split(a.str, '\n');
		a.taible2 = ft_split(a.str, '\n');
		ft_check(&a);
		ft_images(&a);
		fill_win(&a);
		mlx_hook(a.win, 2, 0, move, &a);
		mlx_hook(a.win, 17, 0, ft_close, &a);
		mlx_loop(a.mlx);
	}
	else
		ft_abort(7);
}
