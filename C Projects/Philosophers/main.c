/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:01:57 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/05/29 23:07:18 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_all(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->print_mutex);
	pthread_mutex_destroy(&rules->meal_mutex);
	free(rules->forks);
	free(philos);
	return (0);
}

static int	create_philosopher_threads(t_philo *philos, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (pthread_create(&philos[i].thread_id,
				NULL, routine, &philos[i]) != 0)
		{
			printf("Error: Failed to create thread%d\n", i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	join_all_threads(t_philo *philos, pthread_t monitor, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_join(philos[i].thread_id, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
}

int	main(int ac, char **av)
{
	t_rules		rules;
	t_philo		*philos;
	pthread_t	monitor;

	if (init_all(&rules, &philos, ac, av) != 0)
		return (1);
	if (create_philosopher_threads(philos, rules.number_of_philosophers) != 0)
		return (1);
	if (pthread_create(&monitor, NULL, monitor_routine, philos) != 0)
	{
		printf("Error: Failed to create monitor thread\n");
		return (1);
	}
	join_all_threads(philos, monitor, rules.number_of_philosophers);
	clear_all(&rules, philos);
	return (0);
}
