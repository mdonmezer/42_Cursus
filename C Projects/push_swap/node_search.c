/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:28:18 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/24 00:47:24 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_best_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_node	*find_min(t_node *stack)
{
	long	min;
	t_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	move_min_to_top(t_node **a)
{
	while ((*a)->number != find_min(*a)->number)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
