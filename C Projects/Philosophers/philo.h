/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:52:10 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/05/29 23:04:13 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_rules
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				finished;
	long			start_time;
	int				dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_mutex;
}	t_rules;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long			last_meal;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_rules			*rules;
}	t_philo;

int		ft_atoi(const char *str);
long	get_time(void);
void	my_sleep(long time_in_ms);
void	print_status(t_philo *philo, char *message);
int		init_all(t_rules *rules, t_philo **philos, int argc, char **argv);
void	*routine(void *arg);
int		clear_all(t_rules *rules, t_philo *philos);
void	*monitor_routine(void *arg);
int		is_simulation_over(t_rules *rules);
int		check_philosopher_death(t_philo *philo, t_rules *rules);

#endif
