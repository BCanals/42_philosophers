/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:21:29 by becanals          #+#    #+#             */
/*   Updated: 2026/09/07 19:39:04 by becanals         ###   ########.fr       */
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
	pthread_mutex_lock(&me->ate_m);
	gettimeofday(me->ate, NULL);
	pthread_mutex_unlock(&me->ate_m);
	my_printf("is eating\n", elapsed(me), me);
	isleep(me, me->table->time_to_eat);
	pthread_mutex_lock(&me->table->forks[me->fork_a]);
	me->table->forks_s[me->fork_a] = FREE;
	pthread_mutex_unlock(&me->table->forks[me->fork_a]);
	pthread_mutex_lock(&me->table->forks[me->fork_b]);
	me->table->forks_s[me->fork_b] = FREE;
	pthread_mutex_unlock(&me->table->forks[me->fork_b]);
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

int	take_fork(t_philo *me, int id, int once)
{
	
	while (is_sim_live(me->table))
	{
		pthread_mutex_lock(&me->table->forks[id]);
		if (me->table->forks_s[id] == FREE)
		{
			me->table->forks_s[id] = TAKEN;
			pthread_mutex_unlock(&me->table->forks[id]);
			my_printf("has taken a fork\n", elapsed(me), me);
			return (1);
		}
		pthread_mutex_unlock(&me->table->forks[id]);
		usleep(1000);
		if (once)
			return (0);
	}
	return (0);
}

void	ft_think(t_philo *me)
{
	my_printf("is thinking\n", elapsed(me), me);

	int	a_taken;
	int b_taken;

	b_taken = 0;
	a_taken = take_fork(me, me->fork_a, ONCE);
	if (!a_taken)
	{
		b_taken = take_fork(me, me->fork_b, ONCE);
		if (!take_fork(me, me->fork_a, LOOP))
			return ;
	}
	if (!b_taken)
		take_fork(me, me->fork_b, LOOP);
	pthread_mutex_lock(&me->action_m);
	me->action = EAT;
	pthread_mutex_unlock(&me->action_m);
}
