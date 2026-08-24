/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:19:24 by bizcru            #+#    #+#             */
/*   Updated: 2026/07/29 18:46:05 by bizcru           ###   ########.fr       */
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

	printf("_____ BUILDING...  _______\n");
	philos_num = 10;
	table = create_table(philos_num);
	if (table == NULL)
		return (1);
	i = -1;
	while (++i < philos_num)
		pthread_create(&table->ids[i], NULL, (void *)&ph_behave, table->philos[i]);
	i = -1;
	gettimeofday(table->ini_t, NULL);
	printf("______ START ! _____\n");
	pthread_mutex_unlock(&table->start);
	while (++i < philos_num)
		pthread_join(table->ids[i], NULL);
	printf("THE END\n");
	cleanup(table);
	return (0);
}

