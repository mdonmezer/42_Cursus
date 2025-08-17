/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:52:10 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/05/31 16:12:44 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	has_philosopher_eaten_enough(t_philo *philo, t_rules *rules)
{
	int	eaten_enough;

	eaten_enough = 0;
	pthread_mutex_lock(&rules->meal_mutex);
	if (rules->must_eat_count != -1
		&& philo->eat_count >= rules->must_eat_count)
	{
		eaten_enough = 1;
	}
	pthread_mutex_unlock(&rules->meal_mutex);
	return (eaten_enough);
}

static int	check_philosopher_death_condition(t_philo *philo, t_rules *rules)
{
	long	time_since_last_meal;

	pthread_mutex_lock(&rules->meal_mutex);
	time_since_last_meal = get_time() - philo->last_meal;
	pthread_mutex_unlock(&rules->meal_mutex);
	if (time_since_last_meal > rules->time_to_die)
	{
		pthread_mutex_lock(&rules->print_mutex);
		if (rules->dead || rules->finished)
		{
			pthread_mutex_unlock(&rules->print_mutex);
			return (0);
		}
		rules->dead = 1;
		printf("%ld %d died\n", get_time() - rules->start_time, philo->id);
		pthread_mutex_unlock(&rules->print_mutex);
		return (1);
	}
	return (0);
}

int	check_philosopher_death(t_philo *philo, t_rules *rules)
{
	if (has_philosopher_eaten_enough(philo, rules))
		return (0);
	return (check_philosopher_death_condition(philo, rules));
}
