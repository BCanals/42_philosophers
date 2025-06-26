/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:28:09 by bcanals-          #+#    #+#             */
/*   Updated: 2025/06/26 17:26:34 by bcanals-         ###   ########.fr       */
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
	unsigned int	i_msec;
	unsigned int	n_msec;
	unsigned int	msec;

	set_now(&now);
	sec = now.tv_sec - ini->tv_sec;
	i_msec = ini->tv_usec / 1000;
	n_msec = now.tv_usec / 1000;
	if (n_msec < i_msec)
	{
		sec--;
		msec = 2000000 - i_msec + n_msec;
	}
	else
		msec = n_msec - i_msec;
	sec *= 1000;
	msec += sec;
	return (msec);
}
