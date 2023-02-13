/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:46:15 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/13 11:46:16 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <fcntl.h>

size_t	ft_strlen(char *s, char p)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != p)
		i++;
	return (i);
}
char	*ft_strdup(char *s1)
{
	size_t	i;
	size_t	y;
	char	*f;

	if (!s1)
		return (NULL);
	y = 0;
	i = ft_strlen(s1, '\0');
	f = malloc((i + 1) * sizeof(char));
	if (!f)
		return (0);
	while (y < i)
	{
		f[y] = s1[y];
		y++;
	}
	f[y] = '\0';
	return (f);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1, '\0') + ft_strlen(s2, '\0') + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	free(s1);
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[i] = '\0';
	return (str);
}
static size_t	nbr_of_words(char *s, char c)
{
	size_t	k;
	size_t	h;
	size_t	l;

	k = 0;
	h = 0;
	l = 0;
	while (s[k])
	{
		if (s[k] != c && h == 0)
		{
			l++;
			h = 1;
		}
		else if (s[k] == c && h == 1)
		{
			h = 0;
		}
		k++;
	}
	return (l);
}

static char	**free_all(char **str, size_t max)
{
	int	i;

	i = max;
	while (i >= 0)
		free(str[i--]);
	free (str);
	return (0);
}

static size_t	leakskiller(char *s, unsigned int start, size_t len)
{
	if (ft_strlen(s + start, '\0') >= len)
	{
		return (len);
	}
	else
	{
		return (ft_strlen(s + start, '\0'));
	}
}

char	*ft_substr(char*s, unsigned int start, size_t len)
{
	size_t	o;
	char	*p;

	if (!s)
		return (0);
	if (ft_strlen(s, '\0') < (size_t)start)
		return (ft_strdup(""));
	p = malloc((leakskiller(s, start, len) + 1) * sizeof(char));
	if (!p)
		return (0);
	o = 0;
	while (o < len && s[start + o])
	{
		p[o] = s[start + o];
		o++;
	}
	p[o] = '\0';
	return (p);
}
static char	**ft_return(char *s, char c, char **p)
{
	size_t	e;
	size_t	u;
	size_t	a;

	u = 0;
	a = 0;
	while (u < nbr_of_words((char *)s, c))
	{
		while (s[a] == c && s[a] != '\0')
			a++;
		e = a;
		while (s[e] != c && s[e] != '\0')
			e++;
		p[u] = ft_substr((char *)s, a, e - a);
		if (!p[u])
		{
			return (free_all(p, u));
		}
		u++;
		a = e;
	}
	p[u] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;

	if (!s)
		return (0);
	p = malloc((nbr_of_words((char *)s, c) + 1) * (sizeof(char *)));
	if (!p)
		return (0);
	return (ft_return((char *)s, c, p));
}


static char	*reading_map(char *str)
{
	char	*buffer;
	int		readvl;
    readvl = 1;
    char *line;

    line = NULL;
    int fd = open(str, O_RDONLY);
	buffer = malloc((5 + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (readvl)
	{
		readvl = read(fd, buffer, 5);
		if (readvl == -1)
			return (free(line), free(buffer), NULL);
		else if (!readvl && !line)
			return (free(buffer), NULL);
		else if (!readvl)
			return (free(buffer), line);
		buffer[readvl] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (free(buffer), line);
}

typedef struct data
{
	void *mlx;
	void *win;
	void *grn;
	void *wall;
	int width;
	int height;
	void *ply;
	void *dor;
	void *enemy;
	char *str;
	void *col;
	char **taible;
	int i ;
	int h ;
}t_data ;

void fill_win(t_data *a)
{
	a->i = 0;
	a->h = 0;
	while ((a->taible)[a->i])
	{
		a->h = 0;
		while (a->taible[a->i][a->h])
		{
		printf("%d\n",a->i);
			if (a->taible[a->i][a->h] == '1')
				mlx_put_image_to_window(a->mlx, a->win, a->wall, a->width * a->h , a->height * a->i);
			else if (a->taible[a->i][a->h] == '0')
				mlx_put_image_to_window(a->mlx, a->win, a->grn, a->width * a->h , a->height * a->i);
			else if (a->taible[a->i][a->h] == 'P')
			{
				mlx_put_image_to_window(a->mlx, a->win, a->grn, a->width * a->h , a->height * a->i);
				mlx_put_image_to_window(a->mlx, a->win, a->ply, a->width * a->h , a->height * a->i);
			}
			else if (a->taible[a->i][a->h] == 'C')
			{
				mlx_put_image_to_window(a->mlx, a->win, a->grn, a->width * a->h , a->height * a->i);
				mlx_put_image_to_window(a->mlx, a->win, a->col,  a->width * a->h , a->height * a->i);
			}			
			else if (a->taible[a->i][a->h] == 'E')
			{
				mlx_put_image_to_window(a->mlx, a->win, a->grn, a->width * a->h , a->height * a->i);
				mlx_put_image_to_window(a->mlx, a->win, a->dor,  a->width * a->h , a->height * a->i);
			}			
			// else if (a->taible[a->i][a->h] == 'E')
			// {
			// 	mlx_put_image_to_window(a->mlx, a->win, a->grn, a->width * a->h , a->height * a->i);
			// 	mlx_put_image_to_window(a->mlx, a->win, a->dor,  a->width * a->h , a->height * a->i);
			// }
			a->h++;
		}
		a->i++;
	}
}

int main(int argc , char **argv )
{
	t_data a;
	a.i = 0;
	a.mlx = mlx_init();
	a.str = reading_map(argv[1]);
	a.taible = ft_split(a.str,'\n');
	while (a.taible[a.i])
		a.i++;
	a.grn = mlx_xpm_file_to_image(a.mlx, "../utils/gr.xpm", &a.width, &a.height);
	a.col = mlx_xpm_file_to_image(a.mlx, "../utils/l7am2.xpm", &a.width, &a.height);
	a.dor = mlx_xpm_file_to_image(a.mlx, "../utils/door1sghir.xpm", &a.width, &a.height);
	// a.enemy = mlx_xpm_file_to_image(a.mlx, "enemy.xpm", &a.width, &a.height);
	a.wall = mlx_xpm_file_to_image(a.mlx, "../utils/wall.xpm", &a.width, &a.height);
	a.ply = mlx_xpm_file_to_image(a.mlx, "../utils/player.xpm", &a.width, &a.height);
	a.win = mlx_new_window(a.mlx, ft_strlen(a.taible[1],'\0') * a.width, a.i * a.height, "So_long");
	fill_win(&a);
	mlx_loop(a.mlx);

}