/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:03:23 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/17 18:19:16 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
