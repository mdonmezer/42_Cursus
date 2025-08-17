/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:33:56 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/24 00:47:50 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	transfer_to_a(t_node **a, t_node **b)
{
	position_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	update_indices(*a);
	update_indices(*b);
}

static void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	update_indices(*a);
	update_indices(*b);
}

void	position_for_push(t_node **stack, t_node *target_node_of_b,
							char stack_name)
{
	while (*stack != target_node_of_b)
	{
		if (stack_name == 'a')
		{
			if (target_node_of_b->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (target_node_of_b->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	transfer_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = get_best_node(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	position_for_push(a, cheapest_node, 'a');
	position_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}
