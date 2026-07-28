/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:21:29 by becanals          #+#    #+#             */
/*   Updated: 2026/07/27 14:22:08 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

	//usleep(1500000);
void	pickup_forks(t_philo *me);
void	eat(t_philo *me);
void	putdown_forks(t_philo *me);

void	ph_behave(t_philo *me)
{
	pthread_mutex_lock(&me->table->start);
	pthread_mutex_unlock(&me->table->start);
	if (me->id % 2)
		usleep(150000);
	pickup_forks(me);
	printf("%i - forks taken\n", me->id);
	eat(me);
	putdown_forks(me);
	printf("%i - Done!\n", me->id);
}

void	pickup_forks(t_philo *me)
{
	pthread_mutex_lock(&me->table->forks[me->id]);
	if (me->id == 0)
		pthread_mutex_lock(&me->table->forks[me->table->philos_num - 1]);
	else
		pthread_mutex_lock(&me->table->forks[me->id - 1]);
}

void	eat(t_philo *me)
{
	printf("%i - eating\n", me->id);
	usleep(1000);
	printf("%i - eaten\n", me->id);
}

void	putdown_forks(t_philo *me)
{
	pthread_mutex_unlock(&me->table->forks[me->id]);
	if (me->id == 0)
		pthread_mutex_unlock(&me->table->forks[me->table->philos_num - 1]);
	else
		pthread_mutex_unlock(&me->table->forks[me->id - 1]);
}
