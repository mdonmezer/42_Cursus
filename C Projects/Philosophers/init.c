/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:01:52 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/05/29 23:07:12 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_rules(t_rules *rules, int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	rules->number_of_philosophers = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	rules->must_eat_count = -1;
	if (ac == 6)
		rules->must_eat_count = ft_atoi(av[5]);
	if (rules->number_of_philosophers <= 0 || rules->time_to_die < 0
		|| rules->time_to_eat < 0 || rules->time_to_sleep < 0
		|| (ac == 6 && rules->must_eat_count <= 0))
	{
		printf("Error: Invalid argument values\n");
		return (1);
	}
	return (0);
}

static int	handle_single_philo(t_rules *rules)
{
	rules->start_time = get_time();
	printf("0 1 has taken a fork\n");
	my_sleep(rules->time_to_die);
	printf("%d 1 died\n", rules->time_to_die);
	return (1);
}

static int	init_mutexes(t_rules *rules)
{
	int	i;

	rules->forks = malloc(sizeof(pthread_mutex_t)
			* rules->number_of_philosophers);
	if (!rules->forks)
		return (1);
	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&rules->forks[i]);
			free(rules->forks);
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&rules->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&rules->meal_mutex, NULL) != 0)
		return (1);
	return (0);
}

static void	init_philosophers(t_philo *philos, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		philos[i].id = i + 1;
		philos[i].eat_count = 0;
		philos[i].last_meal = rules->start_time;
		philos[i].rules = rules;
		philos[i].left_fork = &rules->forks[i];
		philos[i].right_fork = &rules->forks[(i + 1)
			% rules->number_of_philosophers];
		i++;
	}
}

int	init_all(t_rules *rules, t_philo **philos, int ac, char **av)
{
	if (init_rules(rules, ac, av))
		return (1);
	if (rules->number_of_philosophers == 1)
		return (handle_single_philo(rules));
	if (init_mutexes(rules))
		return (1);
	*philos = malloc(sizeof(t_philo) * rules->number_of_philosophers);
	if (!*philos)
		return (1);
	rules->start_time = get_time();
	rules->dead = 0;
	rules->finished = 0;
	init_philosophers(*philos, rules);
	return (0);
}
