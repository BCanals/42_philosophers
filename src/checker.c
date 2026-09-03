/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 21:44:25 by becanals          #+#    #+#             */
/*   Updated: 2026/09/03 21:17:16 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_ph(t_philo *philo)
{
	philo->table->status = STOP;
	philo->action = PH_STOP;
	printf("%i %i died\n", elapsed(philo), philo->id);
}

void	ft_checker(t_table *table)
{
	struct	timeval time;
	int		i;

	printf("time_to_die = %i\n", table->time_to_die);
	pthread_mutex_lock(&table->start);
	pthread_mutex_unlock(&table->start);
	while (table->status == LIVE)
	{
		gettimeofday(&time, NULL);
		i = -1;
		while (++i < table->philos_num)
		{
			if (starved(table->philos[i], &time) >= table->time_to_die)
			{
				kill_ph(table->philos[i]);
				break;
			}
		}
	}
}
