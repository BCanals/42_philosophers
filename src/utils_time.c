/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:28:09 by bcanals-          #+#    #+#             */
/*   Updated: 2026/09/03 21:58:34 by becanals         ###   ########.fr       */
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
	int	sec;
	int	msec;
	struct timeval	*ini;

	ini = philo->ate;
	sec = now->tv_sec - ini->tv_sec;
	msec = (now->tv_usec - ini->tv_usec) / 1000;
	if (now->tv_usec < ini->tv_usec)
	{
		sec--;
		msec += 1000;
	}
	sec *= 1000;
	msec += sec;
	return (msec);
}
