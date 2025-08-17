/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:36:58 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/24 00:47:54 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nodes(t_node *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_node	*find_max(t_node *stack)
{
	long	max;
	t_node	*max_node;

	max_node = NULL;
	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	sort_three(t_node **a)
{
	t_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->number > (*a)->next->number)
		sa(a);
}

int	is_sorted(t_node *stack)
{
	t_node	*iter;

	if (!stack)
		return (1);
	iter = stack;
	while (iter->next)
	{
		if (iter->number > iter->next->number)
			return (0);
		iter = iter->next;
	}
	return (1);
}

void	optimize_stacks(t_node **a, t_node **b)
{
	int	len_a;

	len_a = count_nodes(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		prepare_stack_a(*a, *b);
		transfer_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		prepare_stack_b(*a, *b);
		transfer_to_a(a, b);
	}
	update_indices(*a);
	move_min_to_top(a);
}
