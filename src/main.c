/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:19:24 by bizcru            #+#    #+#             */
/*   Updated: 2025/06/26 22:38:19 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


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

t_fdata	*initialize(int philos_num)
{
	t_fdata	*fdata;
	int		i;

	fdata = ft_calloc(1, sizeof(t_fdata));
	fdata->ini_t = ft_calloc(1, sizeof(struct timeval));
	set_now(fdata->ini_t);
	fdata->id = calloc(philos_num, sizeof(pthread_t));
	fdata->philos = calloc(philos_num + 1, sizeof(t_philo));
	i = -1;
	while (++i < philos_num)
		fdata->philos[i] = philo_creator(i);
	return (fdata);
}

void	ph_behave(t_fdata *fdata)
{
	usleep(1500000);
	printf("%i - Vols dir?\n", elapsed(fdata->ini_t));
}

void	cleanup(t_fdata *fdata)
{
	int	i;

	free(fdata->id);
	free(fdata->ini_t);
	i = -1;
	while (fdata->philos[++i])
	{
		free(fdata->philos[i]->my_time);
		free(fdata->philos[i]);
	}
	free(fdata->philos);
	free(fdata);
}

int	main(void)
{
	t_fdata	*fdata;
	int philos_num = 100;
	int	i = -1;

	fdata = initialize(philos_num);
	while (++i < philos_num)
		pthread_create(&fdata->id[i], NULL, (void *)&ph_behave, fdata);
	i = -1;
	while (++i < philos_num)
		pthread_join(fdata->id[i], NULL);
	cleanup(fdata);
	return (0);
}
