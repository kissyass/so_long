/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:25:02 by ykissiko          #+#    #+#             */
/*   Updated: 2022/11/18 16:08:55 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_newstr(char *str)
{
	char	*s;
	int		len;
	int		i;

	len = ft_new_strlen(str);
	if (!str[len])
	{
		free(str);
		return (NULL);
	}
	i = ft_strlen1(str);
	s = ft_calloc1(i - len + 1, sizeof(char));
	i = 0;
	len++;
	while (str[i + len])
	{
		s[i] = str[i + len];
		i++;
	}
	s[i] = 0;
	free(str);
	return (s);
}

char	*ft_new_line(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	s = malloc((ft_new_strlen(str) + 2) * sizeof(char));
	if (!s)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		s[i++] = '\n';
	s[i] = 0;
	return (s);
}

char	*ft_read(int fd, char *str)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s)
		return (NULL);
	if (!str)
		str = ft_calloc1(1, 1);
	i = 1;
	while (!ft_found(str) && i != 0)
	{
		i = read(fd, s, BUFFER_SIZE);
		if (i == -1)
		{
			free(s);
			free(str);
			return (NULL);
		}
		s[i] = '\0';
		str = ft_strjoin1(str, s);
	}
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	line = ft_new_line(str);
	str = ft_newstr(str);
	return (line);
}

