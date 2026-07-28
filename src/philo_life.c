/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:21:29 by becanals          #+#    #+#             */
/*   Updated: 2026/07/28 17:01:46 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

	//usleep(1500000);
void	pickup_forks(t_philo *me);
void	putdown_forks(t_philo *me);

void	ph_behave(t_philo *me)
{
	pthread_mutex_lock(&me->table->start);
	pthread_mutex_unlock(&me->table->start);
	while (me->table->status == LIVE)
		me->acts[me->action](me);
}

void	ft_eat(t_philo *me)
{
	pickup_forks(me);
	printf("%i - forks taken\n", me->id);
	printf("%i - eating\n", me->id);
	usleep(1000);
	printf("%i - eaten\n", me->id);
	putdown_forks(me);
	printf("%i - Done!\n", me->id);
	me->action = SLEEP;
}

void	ft_sleep(t_philo *me)
{
	printf("%i - sleeping\n", me->id);
	usleep(1000);
	printf("%i - slept\n", me->id);
	me->action = THINK;
	
}

void	ft_think(t_philo *me)
{
	printf("%i - thinking\n", me->id);
	usleep(1000);
	printf("%i - thought\n", me->id);
	me->action = EAT;
}

void	pickup_forks(t_philo *me)
{
	pthread_mutex_lock(&me->table->forks[me->id]);
	if (me->id == 0)
		pthread_mutex_lock(&me->table->forks[me->table->philos_num - 1]);
	else
		pthread_mutex_lock(&me->table->forks[me->id - 1]);
}

void	putdown_forks(t_philo *me)
{
	pthread_mutex_unlock(&me->table->forks[me->id]);
	if (me->id == 0)
		pthread_mutex_unlock(&me->table->forks[me->table->philos_num - 1]);
	else
		pthread_mutex_unlock(&me->table->forks[me->id - 1]);
}
