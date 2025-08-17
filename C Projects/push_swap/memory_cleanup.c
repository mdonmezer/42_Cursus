/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:24:18 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/24 00:47:09 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	delete_nodes(t_node **s)
{
	t_node	*temp;

	while (*s)
	{
		temp = (*s)->next;
		free(*s);
		*s = temp;
	}
	*s = NULL;
}

void	show_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
