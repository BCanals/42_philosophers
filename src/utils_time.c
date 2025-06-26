/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:28:09 by bcanals-          #+#    #+#             */
/*   Updated: 2025/06/26 21:58:34 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_now(struct timeval *now)
{
	gettimeofday(now, NULL);
}

// Returns the elapsed time since the given timeval until now, in milisec

unsigned int	elapsed(struct timeval *ini)
{
	struct timeval	now;
	unsigned int	sec;
	unsigned int	msec;

	set_now(&now);
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
