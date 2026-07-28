/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:19:55 by bizcru            #+#    #+#             */
/*   Updated: 2026/07/28 17:05:26 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int create_philos(t_table *table);
static t_philo	*create_one_philo(int i, t_table *table);

t_table	*create_table(int philos_num)
{
	t_table	*table;

	table = ft_calloc(1, sizeof(t_table));
	if (!table)
		return (NULL);
	table->ini_t = ft_calloc(1, sizeof(struct timeval));
	if (!table->ini_t)
		return (cleanup(table), NULL);
	table->ids = ft_calloc(philos_num, sizeof(pthread_t));
	table->philos = ft_calloc(philos_num + 1, sizeof(t_philo));
	table->forks = ft_calloc(philos_num, sizeof(pthread_mutex_t));
	if (!table->ids || !table->philos || !table->forks)
		return (cleanup(table), NULL);
	pthread_mutex_init(&table->start, NULL);
	pthread_mutex_lock(&table->start);
	table->philos_num = philos_num;
	table->status = LIVE;
	if (!create_philos(table))
			return (cleanup(table), NULL);
	return (table);
}

static int create_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philos_num)
	{
		table->philos[i] = create_one_philo(i, table);
		if (!table->philos[i])
			return (0);
	}
	return (1);
}

static t_philo	*create_one_philo(int i, t_table *table)
{
	t_philo	*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->my_time = ft_calloc(1, sizeof(struct timeval));
	philo->acts[EAT] = &ft_eat;
	philo->acts[SLEEP] = &ft_sleep;
	philo->acts[THINK] = &ft_think;
	philo->id = i;
	philo->table = table;
	return (philo);
}
