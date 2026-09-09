/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:28:09 by bcanals-          #+#    #+#             */
/*   Updated: 2026/09/09 22:40:19 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Returns the elapsed time since the given timeval until now, in milisec

unsigned int	elapsed(t_philo *philo)
{
	struct timeval	now;
	unsigned int	sec;
	unsigned int	msec;
	struct timeval	*ini;

	ini = philo->table->ini_t;
	gettimeofday(&now, NULL);
	sec = now.tv_sec - ini->tv_sec;
	msec = (now.tv_usec - ini->tv_usec) / 1000;
	if (now.tv_usec < ini->tv_usec)
	{
		sec--;
		msec += 1000;
	}
	sec *= 1000;
	msec += sec;
	return (msec);
}

int	starved(t_philo *philo, struct timeval *now)
{
	int				sec;
	int				msec;
	struct timeval	*ini;

	pthread_mutex_lock(&philo->ate_m);
	ini = philo->ate;
	sec = now->tv_sec - ini->tv_sec;
	msec = (now->tv_usec - ini->tv_usec) / 1000;
	if (now->tv_usec < ini->tv_usec)
	{
		sec--;
		msec += 1000;
	}
	pthread_mutex_unlock(&philo->ate_m);
	sec *= 1000;
	msec += sec;
	return (msec);
}

void	ft_delay(t_philo *me)
{
	usleep(20000);
	pthread_mutex_lock(&me->action_m);
	me->action = EAT;
	pthread_mutex_unlock(&me->action_m);
}

void	isleep(t_philo *philo, int time)
{
	struct timeval	now;
	struct timeval	alarm;

	gettimeofday(&alarm, NULL);
	time_add(&alarm, time);
	gettimeofday(&now, NULL);
	while (time_diff(&now, &alarm) > 0 && is_sim_live(philo->table))
	{
		usleep(1000);
		gettimeofday(&now, NULL);
	}
}
