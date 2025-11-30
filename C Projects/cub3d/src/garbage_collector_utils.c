/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:22:21 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:11:42 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*gc_strdup(t_gc *gc, const char *s)
{
	char	*dup;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = (char *)gc_malloc(gc, len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len + 1);
	return (dup);
}
