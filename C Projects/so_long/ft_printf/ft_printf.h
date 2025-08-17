/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:38:55 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/12/19 16:38:55 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putstr(char *s);
int	ft_unnbr(unsigned long u);
int	ft_pointer(unsigned long ptr);
int	ft_smhex(unsigned int x);
int	ft_bghex(unsigned int x);
int	ft_putchar(char c);
int	ft_putnbr(int n);
#endif