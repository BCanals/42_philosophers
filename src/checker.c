/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 21:44:25 by becanals          #+#    #+#             */
/*   Updated: 2026/09/07 21:14:18 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	kill_sim(t_table *table)
{
	pthread_mutex_lock(&table->status_m);
	table->status = STOP;
	pthread_mutex_unlock(&table->status_m);
}

static void	kill_ph(t_philo *philo)
{
	kill_sim(philo->table);
	pthread_mutex_lock(&philo->action_m);
	philo->action = PH_STOP;
	pthread_mutex_unlock(&philo->action_m);
	pthread_mutex_lock(&philo->table->print);
	printf("%i %i died\n", elapsed(philo), philo->id + 1);
	pthread_mutex_unlock(&philo->table->print);
}

void	ft_checker(t_table *table)
{
	struct timeval	time;
	int				i;
	int				finished;

	pthread_mutex_lock(&table->start);
	pthread_mutex_unlock(&table->start);
	while (is_sim_live(table))
	{
		finished = 0;
		gettimeofday(&time, NULL);
		i = -1;
		while (++i < table->philos_num)
		{
			if (starved(table->philos[i], &time) >= table->time_to_die)
			{
				kill_ph(table->philos[i]);
				break ;
			}
			if (get_my_action(table->philos[i]) == PH_STOP)
				finished++;
		}
		if (finished == table->philos_num)
			kill_sim(table);
		usleep(500);
	}
}
