/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:19:24 by bizcru            #+#    #+#             */
/*   Updated: 2026/07/27 14:24:59 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*init_table(int philos_num);
t_philo	*philo_creator(int i, t_table *table);

int	main(void)
{
	t_table	*table;
	int		i;
	int		philos_num;

	philos_num = 4;
	table = init_table(philos_num);
	if (table == NULL)
		return (1);
	i = -1;
	while (++i < philos_num)
		pthread_create(&table->ids[i], NULL, (void *)&ph_behave, table->philos[i]);
	i = -1;
	gettimeofday(table->ini_t, NULL);
	pthread_mutex_unlock(&table->start);
	while (++i < philos_num)
		pthread_join(table->ids[i], NULL);
	printf("THE END\n");
	cleanup(table);
	return (0);
}

t_table	*init_table(int philos_num)
{
	t_table	*table;
	int		i;

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
	i = -1;
	while (++i < philos_num)
	{
		table->philos[i] = philo_creator(i, table);
		if (!table->philos[i])
			return (cleanup(table), NULL);
	}
	return (table);
}

t_philo	*philo_creator(int i, t_table *table)
{
	t_philo	*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->my_time = ft_calloc(1, sizeof(struct timeval));
	philo->id = i;
	philo->table = table;
	return (philo);
}
