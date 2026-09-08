/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:21:29 by becanals          #+#    #+#             */
/*   Updated: 2026/09/08 19:24:59 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_alone(t_philo *me);

void	*ph_behave(void *arg)
{
	t_philo	*me;

	me = (t_philo *)arg;
	pthread_mutex_lock(&me->table->start);
	pthread_mutex_unlock(&me->table->start);
	if (me->table->philos_num == 1)
		return (ft_alone(me), NULL);
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
	pthread_mutex_unlock(&me->table->forks[me->fork_a]);
	pthread_mutex_unlock(&me->table->forks[me->fork_b]);
	me->eaten++;
	pthread_mutex_lock(&me->action_m);
	me->action = SLEEP;
	pthread_mutex_unlock(&me->action_m);
	if (me->table->eat_times && me->table->eat_times == me->eaten)
	{
		pthread_mutex_lock(&me->action_m);
		me->action = PH_STOP;
		pthread_mutex_unlock(&me->action_m);
	}
}

void	ft_sleep(t_philo *me)
{
	my_printf("is sleeping\n", elapsed(me), me);
	isleep(me, me->table->time_to_sleep);
	pthread_mutex_lock(&me->action_m);
	me->action = THINK;
	pthread_mutex_unlock(&me->action_m);
}

void	ft_think(t_philo *me)
{
	my_printf("is thinking\n", elapsed(me), me);
	pthread_mutex_lock(&me->table->forks[me->fork_a]);
	my_printf("has taken a fork\n", elapsed(me), me);
	pthread_mutex_lock(&me->table->forks[me->fork_b]);
	my_printf("has taken a fork\n", elapsed(me), me);
	pthread_mutex_lock(&me->action_m);
	me->action = EAT;
	pthread_mutex_unlock(&me->action_m);
}

static void	ft_alone(t_philo *me)
{
	my_printf("is thinking\n", elapsed(me), me);
	pthread_mutex_lock(&me->table->forks[me->fork_a]);
	my_printf("has taken a fork\n", elapsed(me), me);
	while (is_sim_live(me->table))
		;
	pthread_mutex_unlock(&me->table->forks[me->fork_a]);
}
