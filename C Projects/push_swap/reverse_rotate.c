/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:30:46 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/24 00:47:37 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node **s)
{
	t_node	*temp;
	t_node	*prev;

	if (!s || !(*s) || !(*s)->next)
		return ;
	prev = *s;
	while (prev->next->next)
		prev = prev->next;
	temp = prev->next;
	prev->next = NULL;
	temp->next = *s;
	*s = temp;
}

void	rra(t_node **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
