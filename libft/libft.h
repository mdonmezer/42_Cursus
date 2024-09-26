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

#endif
