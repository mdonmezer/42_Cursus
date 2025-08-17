/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:30:58 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/24 00:47:45 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_new_node(int number)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->number = number;
	new->next = NULL;
	return (new);
}

static void	add_node_to_stack(t_node **stack, t_node *new)
{
	t_node	*temp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

static int	process_number(char *str, t_node **stack)
{
	int		num;
	t_node	*new_node;

	num = (int)ft_atol(str);
	new_node = create_new_node(num);
	if (!new_node)
		return (0);
	add_node_to_stack(stack, new_node);
	return (1);
}

static t_node	*init_stack_from_input(char **input, int start, t_node **a)
{
	int	i;

	i = start;
	while (input[i])
	{
		if (!process_number(input[i++], a))
			return (NULL);
	}
	return (*a);
}

t_node	*create_stack(char **argv, int argc, t_node **a)
{
	char	**arr;
	t_node	*result;

	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (!arr)
			return (NULL);
		result = init_stack_from_input(arr, 0, a);
		clean_split(arr);
	}
	else
		result = init_stack_from_input(argv, 1, a);
	if (!result)
		delete_nodes(a);
	return (result);
}
