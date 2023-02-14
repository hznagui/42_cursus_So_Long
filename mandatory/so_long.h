/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:27:51 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/14 14:39:42 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct data
{
	void	*mlx;
	void	*win;
	void	*grn;
	void	*wall;
	int		width;
	int		height;
	void	*ply;
	void	*ply2;
	void	*dor;
	void	*enemy;
	char	*str;
	void	*col;
	void	*opndor;
	char	**taible;
	int		i;
	int		d;
	int		h;
}			t_alldata;

size_t		ft_strlen(char *s, char p);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
size_t		leakskiller(char *s, unsigned int start, size_t len);
char		*ft_substr(char *s, unsigned int start, size_t len);
size_t		nbr_of_words(char *s, char c);
char		**free_all(char **str, size_t max);
char		**ft_return(char *s, char c, char **p);
char		**ft_split(char const *s, char c);
char		*reading_map(char *str);
void		find_player(t_alldata *a);
int			find_meat(char **a);
int			ft_close(void *a);
void		fill_win(t_alldata *a);

#endif