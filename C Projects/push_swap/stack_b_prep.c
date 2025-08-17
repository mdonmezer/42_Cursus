/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_prep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:31:02 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/24 00:47:47 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_indices(t_node *stack)
{
	int		i;
	int		median;

	i = 0;
	if (!stack)
		return ;
	median = count_nodes(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->above_median = (i <= median);
		stack = stack->next;
		++i;
	}
}

void	set_target_b(t_node *a, t_node *b)
{
	t_node	*iter_a;
	t_node	*target_node;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		iter_a = a;
		while (iter_a)
		{
			if (iter_a->number > b->number && iter_a->number < best_match)
			{
				best_match = iter_a->number;
				target_node = iter_a;
			}
			iter_a = iter_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	prepare_stack_b(t_node *a, t_node *b)
{
	update_indices(a);
	update_indices(b);
	set_target_b(a, b);
}
