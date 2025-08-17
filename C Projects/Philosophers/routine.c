/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:02:08 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/05/29 23:07:28 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->id % 2 == 0)
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	else
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	pthread_mutex_lock(first);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(second);
	print_status(philo, "has taken a fork");
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(10);
	while (!is_simulation_over(philo->rules))
	{
		take_forks(philo);
		pthread_mutex_lock(&philo->rules->meal_mutex);
		print_status(philo, "is eating");
		philo->last_meal = get_time();
		philo->eat_count++;
		pthread_mutex_unlock(&philo->rules->meal_mutex);
		my_sleep(philo->rules->time_to_eat);
		drop_forks(philo);
		if (philo->rules->must_eat_count != -1
			&& philo->eat_count >= philo->rules->must_eat_count)
			break ;
		print_status(philo, "is sleeping");
		my_sleep(philo->rules->time_to_sleep);
		print_status(philo, "is thinking");
	}
	return (NULL);
}

void	print_status(t_philo *philo, char *msg)
{
	long	time;

	pthread_mutex_lock(&philo->rules->print_mutex);
	time = get_time() - philo->rules->start_time;
	if (!philo->rules->dead && !philo->rules->finished)
		printf("%ld %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->rules->print_mutex);
}
