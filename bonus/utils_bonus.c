/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:34:12 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/16 15:27:08 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	nbr_of_words(char *s, char c)
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

/*----------------------------------------------------------------*/
char	**free_all(char **str, size_t max)
{
	int	i;

	i = max;
	while (i >= 0)
		free(str[i--]);
	free(str);
	return (0);
}

/*----------------------------------------------------------------*/

char	**ft_return(char *s, char c, char **p)
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
/*----------------------------------------------------------------*/

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

/*----------------------------------------------------------------*/

char	*reading_map(char *str)
{
	char	*buffer;
	int		readvl;
	char	*line;
	int		fd;

	readvl = 1;
	line = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_abort(6);
	buffer = malloc((5) * sizeof(char));
	if (!buffer)
		ft_abort(1);
	while (readvl)
	{
		readvl = read(fd, buffer, 5);
		if (readvl == -1)
			return (free(line), free(buffer), ft_abort(0), NULL);
		else if (!readvl && !line)
			return (free(buffer), ft_abort(8), NULL);
		else if (!readvl)
			return (free(buffer), line);
		buffer[readvl] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (free(buffer), line);
}
