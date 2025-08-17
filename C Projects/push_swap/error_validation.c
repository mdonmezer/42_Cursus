/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:23:40 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/24 00:47:14 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(char *s)
{
	int	i;

	i = 0;
	if (!(s[0] == '-' || s[0] == '+' || (s[0] <= '9' && s[0] >= '0')))
		return (1);
	if ((s[0] == '-' || s[0] == '+') && !(s[1] <= '9' && s[1] >= '0'))
		return (1);
	while (s[++i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
	}
	return (0);
}

int	check_duplicates(char **argv, int i)
{
	int		j;
	long	n1;
	long	n2;

	j = i;
	n1 = ft_atol(argv[i]);
	n2 = ft_atol(argv[j]);
	if (n1 == -2147483649 || n2 == -2147483649)
		return (1);
	while (argv[++j])
	{
		n1 = ft_atol(argv[i]);
		n2 = ft_atol(argv[j]);
		if (n1 == n2)
			return (1);
		else if (n1 == -2147483649 || n2 == -2147483649)
			return (1);
	}
	return (0);
}

int	validate_input(char **argv, int argc)
{
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
			return (clean_split(args), show_error(), 1);
		while (args[i])
		{
			if (check_syntax(args[i]) || check_duplicates(args, i))
				return (clean_split(args), show_error(), 1);
			i++;
		}
		clean_split(args);
	}
	while (argv[++i] && argc != 2)
	{
		if (check_syntax(argv[i]) || check_duplicates(argv, i))
			return (show_error(), 1);
	}
	return (0);
}
