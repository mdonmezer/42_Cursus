/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:51:47 by mdonmezer         #+#    #+#             */
/*   Updated: 2025/11/28 17:08:52 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int			gnl_strlen(const char *s);
const char	*gnl_strchr(const char *s, int c);
char		*gnl_strjoin(char *s1, char *s2);
char		*gnl_strdup(const char *s);
char		*gnl_substr(const char *s, unsigned int start, size_t len);
char		*get_next_line(int fd);
char		*ft_append_to_left_one(int fd, char *buf);

#endif
