/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:22:40 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:11:39 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	gc_init(t_gc *gc)
{
	gc->head = NULL;
}

int	gc_register(t_gc *gc, void *ptr)
{
	t_gc_node	*node;

	if (!ptr)
		return (-1);
	node = (t_gc_node *)malloc(sizeof(t_gc_node));
	if (!node)
		return (-1);
	node->ptr = ptr;
	node->next = gc->head;
	gc->head = node;
	return (0);
}

void	*gc_malloc(t_gc *gc, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	if (gc_register(gc, ptr) != 0)
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

void	*gc_calloc(t_gc *gc, size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (!ptr)
		return (NULL);
	if (gc_register(gc, ptr) != 0)
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

void	gc_free_all(t_gc *gc)
{
	t_gc_node	*node;
	t_gc_node	*next;

	if (!gc || !gc->head)
		return ;
	node = gc->head;
	while (node)
	{
		next = node->next;
		if (node->ptr)
			free(node->ptr);
		free(node);
		node = next;
	}
	gc->head = NULL;
}
