/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:28:42 by ykissiko          #+#    #+#             */
/*   Updated: 2023/02/10 12:39:17 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_new_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_found(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen1(s1) + ft_strlen1(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	free (s1);
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

char	*ft_calloc1(size_t count, size_t size)
{
	char	*p;
	size_t	i;
	size_t	n;

	n = count * size;
	p = malloc(n);
	if (!p)
		return (NULL);
	i = 0;
	while (i < n)
		p[i++] = '\0';
	return (p);
}
