/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:21:29 by becanals          #+#    #+#             */
/*   Updated: 2026/07/29 17:53:17 by bizcru           ###   ########.fr       */
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
	printf("%i - is eating\n", me->id);
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
	printf("%i - is sleeping\n", me->id);
	usleep(me->table->time_to_sleep);
	me->action = THINK;
	
}

void	ft_think(t_philo *me)
{
	printf("%i - is thinking\n", me->id);
	pthread_mutex_lock(&me->table->forks[me->id]);
	printf("%i - has taken a fork\n", me->id);
	if (me->id == 0)
		pthread_mutex_lock(&me->table->forks[me->table->philos_num - 1]);
	else
		pthread_mutex_lock(&me->table->forks[me->id - 1]);
	printf("%i - has taken a fork\n", me->id);
	me->action = EAT;
}
