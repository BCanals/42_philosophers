/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 21:44:25 by becanals          #+#    #+#             */
/*   Updated: 2026/09/07 18:28:02 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_ph(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->status_m);
	philo->table->status = STOP;
	pthread_mutex_unlock(&philo->table->status_m);
	pthread_mutex_lock(&philo->table->philos_m[philo->id]);
	philo->action = PH_STOP;
	pthread_mutex_unlock(&philo->table->philos_m[philo->id]);
	my_printf("died\n", elapsed(philo), philo);
}

void	ft_checker(t_table *table)
{
	struct timeval	time;
	int				i;

	pthread_mutex_lock(&table->start);
	pthread_mutex_unlock(&table->start);
	while (is_sim_live(table))
	{
		gettimeofday(&time, NULL);
		i = -1;
		while (++i < table->philos_num)
		{
			if (starved(table->philos[i], &time) >= table->time_to_die)
			{
				kill_ph(table->philos[i]);
				break ;
			}
		}
		usleep(500);
	}
}
