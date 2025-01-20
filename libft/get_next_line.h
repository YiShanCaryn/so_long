/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:03:54 by yishan            #+#    #+#             */
/*   Updated: 2025/01/18 15:46:21 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20

# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*read_file(int fd, char *res);
char	*ft_free(char *res, char	*buf);
char	*ft_line(char	*buffer);
char	*ft_next(char *buffer);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementnum, size_t elementsize);
char	*ft_strchr(const char	*string, int searchChar);
char	*ft_strjoin(const char	*s1, const char	*s2);
size_t	gt_strlen(const char	*s);

#endif
