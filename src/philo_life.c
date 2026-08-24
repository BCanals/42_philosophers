/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:21:29 by becanals          #+#    #+#             */
/*   Updated: 2026/08/24 20:08:29 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

	//usleep(1500000);

void	ph_behave(t_philo *me)
{
	pthread_mutex_lock(&me->table->start);
	pthread_mutex_unlock(&me->table->start);
	while (me->table->status == LIVE)
		me->acts[me->action](me);
}

void	ft_eat(t_philo *me)
{
	printf("%i %i is eating\n", elapsed(me), me->id);
	usleep(me->table->time_to_eat);
	pthread_mutex_unlock(&me->table->forks[me->id]);
	if (me->id == 0)
		pthread_mutex_unlock(&me->table->forks[me->table->philos_num - 1]);
	else
		pthread_mutex_unlock(&me->table->forks[me->id - 1]);
	me->action = SLEEP;
}

void	ft_sleep(t_philo *me)
{
	printf("%i %i is sleeping\n", elapsed(me), me->id);
	usleep(me->table->time_to_sleep);
	me->action = THINK;
}

void	ft_think(t_philo *me)
{
	printf("%i %i is thinking\n", elapsed(me), me->id);
	if (me->id % 2)
	{
		pthread_mutex_lock(&me->table->forks[me->id]);
		printf("%i %i has taken a fork\n", elapsed(me), me->id);
	}
	if (me->id == 0)
		pthread_mutex_lock(&me->table->forks[me->table->philos_num - 1]);
	else
		pthread_mutex_lock(&me->table->forks[me->id - 1]);
	printf("%i %i has taken a fork\n", elapsed(me), me->id);
	if (!(me->id % 2))
	{
		pthread_mutex_lock(&me->table->forks[me->id]);
		printf("%i %i has taken a fork\n", elapsed(me), me->id);
	}
	me->action = EAT;
}
