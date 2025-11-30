/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:54:56 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/01 22:01:18 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memcpy(void	*out, const void	*src, unsigned int len)
{
	unsigned int	i;
	unsigned char	*o;
	unsigned char	*s;

	i = 0;
	if (out == NULL && src == NULL)
		return ((void *)src);
	o = (unsigned char *) out;
	s = (unsigned char *) src;
	while (i++ < len)
		*o++ = *s++;
	return (out);
}

void	*ft_bzero(void	*s, unsigned int len)
{
	unsigned int	i;
	unsigned char	*pt;

	i = 0;
	pt = (unsigned char *)s;
	while (i < len)
		pt[i++] = 0;
	return (s);
}

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
	{
		return (p);
	}
	ft_bzero(p, count * size);
	return (p);
}
