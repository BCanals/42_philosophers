/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:19:24 by bizcru            #+#    #+#             */
/*   Updated: 2025/06/26 13:42:39 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philos *initialize()
{
	t_philos *philos;

	philos = ft_calloc(1, sizeof(t_philos));
	philos->id = calloc(1, sizeof(pthread_t));
	return philos;
}

void ph_behave()
{
	printf("Vols dir?\n");

}

void cleanup(t_philos *philos)
{
	free(philos->id);
	free(philos);
}

int main()
{
	t_philos	*philos;

	philos = initialize();
	pthread_create(philos->id, NULL, (void *)&ph_behave, NULL);
	pthread_join(*(philos->id), NULL);
	cleanup(philos);
	return 0;
}
