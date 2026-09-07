/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:19:55 by bizcru            #+#    #+#             */
/*   Updated: 2026/09/07 21:37:31 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		load_params(t_table *table, int params[]);
static int		create_philos(t_table *table);
static t_philo	*create_one_philo(int i, t_table *table);
static void		init_mutexes(t_table *table);

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
	if (!table->ids || !table->philos || !table->forks)
		return (cleanup(table), NULL);
	load_params(table, params);
	init_mutexes(table);
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

static void	init_mutexes(t_table *table)
{
	int	i;

	pthread_mutex_init(&table->start, NULL);
	pthread_mutex_init(&table->print, NULL);
	i = -1;
	while (++i < table->philos_num)
		pthread_mutex_init(&table->forks[i], NULL);
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
		pthread_mutex_init(&table->philos[i]->ate_m, NULL);
		pthread_mutex_init(&table->philos[i]->action_m, NULL);
		if (!(i % 2))
			table->philos[i]->action = DELAY;
	}
	pthread_mutex_lock(&table->start);
	return (1);
}

static t_philo	*create_one_philo(int i, t_table *table)
{
	t_philo	*me;

	me = ft_calloc(1, sizeof(t_philo));
	if (!me)
		return (NULL);
	me->ate = ft_calloc(1, sizeof(struct timeval));
	if (!me->ate)
		return (free(me), NULL);
	me->acts[EAT] = &ft_eat;
	me->acts[SLEEP] = &ft_sleep;
	me->acts[THINK] = &ft_think;
	me->acts[DELAY] = &ft_delay;
	me->action = THINK;
	me->id = i;
	me->table = table;
	me->fork_a = me->id;
	me->fork_b = me->id;
	if (me->id % 2)
		me->fork_b --;
	else
		me->fork_a --;
	if (me->id == 0)
		me->fork_a = me->table->philos_num - 1;
	return (me);
}
