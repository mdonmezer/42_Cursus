/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:29:39 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/24 00:47:31 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(1);
	if (argc == 2 && !argv[1][0])
		show_error();
	validate_input(argv, argc);
	create_stack(argv, argc, &a);
	if (!is_sorted(a))
	{
		if (count_nodes(a) == 2)
			sa(&a);
		else if (count_nodes(a) == 3)
			sort_three(&a);
		else
			optimize_stacks(&a, &b);
	}
	delete_nodes(&a);
	delete_nodes(&b);
	return (0);
}
