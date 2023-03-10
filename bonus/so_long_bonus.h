/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:27:51 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/17 18:16:28 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	char	*nbr;
	void	*wall;
	int		width;
	int		height;
	void	*ply;
	void	*ply2;
	void	*dor;
	void	*enemy1;
	void	*enemy2;
	void	*enemy3;
	void	*enemy4;
	char	*str;
	void	*col;
	void	*opndor;
	char	**taible;
	char	**taible2;
	int		i;
	int		n;
	int		z;
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
char		*reading_map(char *str, char *line, int readvl);
void		find_player(t_alldata *a);
int			find_meat(char **a);
int			ft_close(void *a);
void		fill_win(t_alldata *a);
void		ft_abort(int i);
void		ft_putnbr(int n);
void		ft_putchar(char c);
void		ft_check(t_alldata *a);
void		check_name(char *h);
char		*ft_itoa(int n);
void		skip_nl(t_alldata *a);
int			ft_close(void *a);
void		fill_anime(t_alldata *a);
int			anime(t_alldata *a);
int			move(int keycode, t_alldata *a);
void		images(t_alldata *a);
void		images2(t_alldata *a);
void		ft_check(t_alldata *a);
void		fill_win2(t_alldata *a);
void		fill_win(t_alldata *a);
void		move2(int keycode, t_alldata *a);
int			find_exit(char **a);
int			find_meat(char **a);
void		find_path(int i, int h, t_alldata *a);
void		check_nb(t_alldata *a, int P, int C, int E);
void		check_size(t_alldata *a, int k, int y);
#endif