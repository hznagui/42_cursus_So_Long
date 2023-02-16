/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:30:23 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/16 15:27:10 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
/*----------------------------------------------------------------*/

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

/*----------------------------------------------------------------*/
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
/*----------------------------------------------------------------*/

size_t	leakskiller(char *s, unsigned int start, size_t len)
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
/*----------------------------------------------------------------*/

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
