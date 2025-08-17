/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:06:50 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/05/29 23:03:12 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	count_philosophers_who_ate_enough(t_philo *philos, t_rules *rules)
{
	int	i;
	int	ate_enough_count;

	ate_enough_count = 0;
	i = 0;
	while (i < rules->number_of_philosophers)
	{
		pthread_mutex_lock(&rules->meal_mutex);
		if (philos[i].eat_count >= rules->must_eat_count)
		{
			ate_enough_count++;
		}
		pthread_mutex_unlock(&rules->meal_mutex);
		i++;
	}
	return (ate_enough_count);
}

static int	check_all_finished(t_philo *philos, t_rules *rules)
{
	int	finished_count;

	if (rules->must_eat_count == -1)
		return (0);
	finished_count = count_philosophers_who_ate_enough(philos, rules);
	if (finished_count == rules->number_of_philosophers)
	{
		pthread_mutex_lock(&rules->print_mutex);
		if (rules->dead || rules->finished)
		{
			pthread_mutex_unlock(&rules->print_mutex);
			return (rules->finished);
		}
		rules->finished = 1;
		pthread_mutex_unlock(&rules->print_mutex);
		return (1);
	}
	return (0);
}

static int	check_all_philosophers(t_philo *philos, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (check_philosopher_death(&philos[i], rules))
			return (1);
		i++;
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philos;
	t_rules	*rules;

	philos = (t_philo *)arg;
	rules = philos[0].rules;
	while (!is_simulation_over(rules))
	{
		if (check_all_philosophers(philos, rules))
			return (NULL);
		if (check_all_finished(philos, rules))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
