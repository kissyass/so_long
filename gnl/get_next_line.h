/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:17:52 by ykissiko          #+#    #+#             */
/*   Updated: 2022/11/18 16:30:48 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *str);
char	*ft_new_line(char *str);
char	*ft_newstr(char *str);
char	*ft_strjoin1(char *s1, char *s2);
int		ft_found(const char *s);
int		ft_new_strlen(char *str);
int		ft_strlen1(char *str);
char	*ft_calloc1(size_t count, size_t size);

#endif
