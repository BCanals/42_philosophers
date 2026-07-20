/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:19:24 by bizcru            #+#    #+#             */
/*   Updated: 2026/07/19 19:28:38 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*init_table(int philos_num);
t_philo	*philo_creator(int i);

int	main(void)
{
	t_table	*table;
	int		i;
	int		philos_num;

	philos_num = 100;
	if ((table = init_table(philos_num)) == NULL)
		return (1);
	i = -1;
	while (++i < philos_num)
		pthread_create(&table->id[i], NULL, (void *)&ph_behave, table);
	i = -1;
	while (++i < philos_num)
		pthread_join(table->id[i], NULL);
	cleanup(table);
	return (0);
}

t_table	*init_table(int philos_num)
{
	t_table	*table;
	int		i;

	table = ft_calloc(1, sizeof(t_table));
	table->ini_t = ft_calloc(1, sizeof(struct timeval));
	gettimeofday(table->ini_t, NULL);
	table->id = calloc(philos_num, sizeof(pthread_t));
	table->philos = calloc(philos_num + 1, sizeof(t_philo));
	i = -1;
	while (++i < philos_num)
		table->philos[i] = philo_creator(i);
	return (table);
}

t_philo	*philo_creator(int i)
{
	t_philo	*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->my_time = ft_calloc(1, sizeof(struct timeval));
	philo->name = i;
	return (philo);
}
