/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:29:20 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/24 00:47:28 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_node **dest, t_node **src)
{
	t_node	*temp;

	if (!src || !(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	pa(t_node **a, t_node **b)
{
	push_node(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a)
{
	push_node(b, a);
	write(1, "pb\n", 3);
}
