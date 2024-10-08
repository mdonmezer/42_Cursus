/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:34:12 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/10/08 19:34:13 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

// is

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

//to

int		ft_atoi(const char *str);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_itoa(int n);

//str

size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *str);
size_t		ft_strlcat(char *dest, const char *src, size_t size);





#endif
