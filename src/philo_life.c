/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:21:29 by becanals          #+#    #+#             */
/*   Updated: 2026/09/04 21:39:08 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ph_behave(void *arg)
{
	t_philo	*me;

	me = (t_philo *)arg;
	pthread_mutex_lock(&me->table->start);
	pthread_mutex_unlock(&me->table->start);
	pthread_mutex_lock(&me->ate_m);
	pthread_mutex_unlock(&me->ate_m);
	while (is_sim_live(me->table) && get_my_action(me) != PH_STOP)
		me->acts[me->action](me);
	return (NULL);
}

void	ft_eat(t_philo *me)
{
	gettimeofday(me->ate, NULL);
	my_printf("is eating\n", elapsed(me), me);
	isleep(me, me->table->time_to_eat);
	pthread_mutex_lock(&me->table->forks[me->id]);
	me->table->forks_s[me->id] = FREE;
	pthread_mutex_unlock(&me->table->forks[me->id]);
	pthread_mutex_lock(&me->table->forks[me->my_fork]);
	me->table->forks_s[me->my_fork] = FREE;
	pthread_mutex_unlock(&me->table->forks[me->my_fork]);
	me->eaten++;
	pthread_mutex_lock(&me->table->philos_m[me->id]);
	me->action = SLEEP;
	pthread_mutex_unlock(&me->table->philos_m[me->id]);
	if (me->table->eat_times && me->table->eat_times == me->eaten)
	{
		pthread_mutex_lock(&me->table->philos_m[me->id]);
		me->action = PH_STOP;
		pthread_mutex_unlock(&me->table->philos_m[me->id]);
	}
}

void	ft_sleep(t_philo *me)
{
	my_printf("is sleeping\n", elapsed(me), me);
	isleep(me, me->table->time_to_sleep);
	pthread_mutex_lock(&me->table->philos_m[me->id]);
	me->action = THINK;
	pthread_mutex_unlock(&me->table->philos_m[me->id]);
}

int	take_fork(t_philo *me, int id)
{
	while (is_sim_live(me->table))
	{
		pthread_mutex_lock(&me->table->forks[id]);
		if (me->table->forks_s[id] == FREE)
		{
			me->table->forks_s[id] = TAKEN;
			pthread_mutex_unlock(&me->table->forks[id]);
			return (1);
		}
		pthread_mutex_unlock(&me->table->forks[id]);
	}
	return (0);
}

void	ft_think(t_philo *me)
{
	my_printf("is thinking\n", elapsed(me), me);
	if (me->id % 2)
	{
		if (take_fork(me, me->id))
			my_printf("has taken a fork\n", elapsed(me), me);
		else
			return ;
	}
	if (take_fork(me, me->my_fork))
		my_printf("has taken a fork\n", elapsed(me), me);
	else
		return ;
	if (!(me->id % 2))
	{
		if (take_fork(me, me->id))
			my_printf("has taken a fork\n", elapsed(me), me);
		else
			return ;
	}
	pthread_mutex_lock(&me->table->philos_m[me->id]);
	me->action = EAT;
	pthread_mutex_unlock(&me->table->philos_m[me->id]);
}
