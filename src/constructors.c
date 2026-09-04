/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:19:55 by bizcru            #+#    #+#             */
/*   Updated: 2026/09/04 20:19:08 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		load_params(t_table *table, int params[]);
static int		create_philos(t_table *table);
static t_philo	*create_one_philo(int i, t_table *table);

t_table	*create_table(int params[])
{
	t_table	*table;

	table = ft_calloc(1, sizeof(t_table));
	if (!table)
		return (NULL);
	table->ini_t = ft_calloc(1, sizeof(struct timeval));
	if (!table->ini_t)
		return (cleanup(table), NULL);
	table->ids = ft_calloc(params[0], sizeof(pthread_t));
	table->philos = ft_calloc(params[0] + 1, sizeof(t_philo));
	table->forks = ft_calloc(params[0], sizeof(pthread_mutex_t));
	table->forks_s = ft_calloc(params[0], sizeof(char));
	table->philos_m = ft_calloc(params[0], sizeof(pthread_mutex_t));
	if (!table->ids || !table->philos || !table->forks || !table->forks_s
		|| !table->philos_m)
		return (cleanup(table), NULL);
	load_params(table, params);
	pthread_mutex_lock(&table->status_m);
	table->status = LIVE;
	pthread_mutex_unlock(&table->status_m);
	if (!create_philos(table))
		return (cleanup(table), NULL);
	return (table);
}

static void	load_params(t_table *table, int params[])
{
	table->philos_num = params[0];
	table->time_to_die = params[1];
	table->time_to_eat = params[2];
	table->time_to_sleep = params[3];
	table->eat_times = params[4];
}

static int	create_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philos_num)
	{
		table->philos[i] = create_one_philo(i, table);
		if (!table->philos[i])
			return (0);
		if (!(i % 2))
			table->philos[i]->action = DELAY;
	}
	pthread_mutex_init(&table->start, NULL);
	pthread_mutex_lock(&table->start);
	return (1);
}

static t_philo	*create_one_philo(int i, t_table *table)
{
	t_philo	*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->ate = ft_calloc(1, sizeof(struct timeval));
	if (!philo->ate)
	{
		free(philo);
		return (NULL);
	}
	philo->eaten = 0;
	philo->acts[EAT] = &ft_eat;
	philo->acts[SLEEP] = &ft_sleep;
	philo->acts[THINK] = &ft_think;
	philo->acts[DELAY] = &ft_delay;
	philo->action = THINK;
	philo->id = i;
	philo->table = table;
	if (philo->id == 0)
		philo->my_fork = philo->table->philos_num - 1;
	else
		philo->my_fork = philo->id - 1;
	return (philo);
}
