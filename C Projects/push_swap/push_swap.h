/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:30:28 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/24 00:47:34 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				index;
	bool			cheapest;
	int				push_cost;
	bool			above_median;
	struct s_node	*target_node;
	int				number;
	struct s_node	*next;
}	t_node;

void	clean_split(char **arr);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	delete_nodes(t_node **s);
void	show_error(void);
long	ft_atol(const char *s);
int		check_syntax(char *s);
int		check_duplicates(char **argv, int i);
int		validate_input(char **argv, int argc);
t_node	*create_stack(char **argv, int argc, t_node **a);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	print_stack(t_node *stack);
char	**ft_split(char const *s, char c);
int		is_sorted(t_node *stack);
int		count_nodes(t_node *stack);
void	swap(t_node **head);
void	sa(t_node **a);
void	sb(t_node **b);
void	rotate(t_node **stack);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
t_node	*find_max(t_node *stack);
void	sort_three(t_node **a);
void	optimize_stacks(t_node **a, t_node **b);
t_node	*get_best_node(t_node *stack);
void	position_for_push(t_node **stack, t_node *top_node, char stack_name);
void	transfer_to_b(t_node **a, t_node **b);
void	push_node(t_node **dest, t_node **src);
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);
void	update_indices(t_node *stack);
void	set_target_a(t_node *a, t_node *b);
void	calculate_costs(t_node *a, t_node *b);
void	mark_cheapest(t_node *stack);
void	prepare_stack_a(t_node *a, t_node *b);
void	set_target_b(t_node *a, t_node *b);
void	prepare_stack_b(t_node *a, t_node *b);
t_node	*find_min(t_node *stack);
void	move_min_to_top(t_node **a);
void	transfer_to_a(t_node **a, t_node **b);
void	rev_rotate(t_node **s);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	rra(t_node **a);

#endif
