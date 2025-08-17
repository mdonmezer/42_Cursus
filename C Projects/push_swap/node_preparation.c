/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_preparation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:28:05 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/24 00:47:21 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_node *a, t_node *b)
{
	t_node	*iter_b;
	t_node	*target_node;
	long	best_match;

	target_node = NULL;
	while (a)
	{
		best_match = LONG_MIN;
		iter_b = b;
		while (iter_b)
		{
			if (iter_b->number < a->number && iter_b->number > best_match)
			{
				best_match = iter_b->number;
				target_node = iter_b;
			}
			iter_b = iter_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	calculate_costs(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = count_nodes(a);
	len_b = count_nodes(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!a->above_median)
			a->push_cost = len_a - a->index;
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - a->target_node->index;
		a = a->next;
	}
}

void	mark_cheapest(t_node *stack)
{
	long	cheapest_value;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	prepare_stack_a(t_node *a, t_node *b)
{
	update_indices(a);
	update_indices(b);
	set_target_a(a, b);
	calculate_costs(a, b);
	mark_cheapest(a);
}
