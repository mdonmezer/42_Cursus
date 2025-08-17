/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:55:45 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/05/29 23:08:02 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_simulation_over(t_rules *rules)
{
	int	result;

	pthread_mutex_lock(&rules->print_mutex);
	result = (rules->dead || rules->finished);
	pthread_mutex_unlock(&rules->print_mutex);
	return (result);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	count;
	int	i;
	int	sign;

	count = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		count = (count * 10) + (str[i] - 48);
		i++;
	}
	return (count * sign);
}
