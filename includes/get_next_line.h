/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:55:59 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/20 21:07:36 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

char	*get_next_line(int fd);
int		ft_find_newl(char *str, int buf_size);
size_t	ft_strlen(char *str);
char	*ft_flush_buf(char *line, char *buf, int index_newl);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize, size_t srcsize);
char	*ft_strjoin(char *s1, char *s2, int s2_size);
void	ft_bufmove(char *buf, int index_newl, int size);

#endif
