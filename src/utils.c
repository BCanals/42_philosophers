/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 19:26:35 by becanals          #+#    #+#             */
/*   Updated: 2026/09/04 20:37:27 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_add(struct timeval *time, int ms)
{
	long	usec;

	usec = (time->tv_usec + ms * 1000);
	if (usec > 1000000)
	{
		time->tv_sec += usec / 1000000;
		usec %= 1000000;
	}
	time->tv_usec = usec;
}

long	time_diff(struct timeval *start, struct timeval *end)
{
	long	diff;

	diff = (end->tv_sec - start->tv_sec) * 1000 * 1000;
	diff += end->tv_usec;
	diff -= start->tv_usec;
	return (diff);
}

int	is_sim_live(t_table *table)
{
	int	rtrn;

	rtrn = 0;
	pthread_mutex_lock(&table->status_m);
	if (table->status == LIVE)
		rtrn += 1;
	pthread_mutex_unlock(&table->status_m);
	return (rtrn);
}

int	get_my_action(t_philo *me)
{
	int	rtrn;

	pthread_mutex_lock(&me->action_m);
	rtrn = me->action;
	pthread_mutex_unlock(&me->action_m);
	return (rtrn);
}
