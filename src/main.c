/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:19:24 by bizcru            #+#    #+#             */
/*   Updated: 2025/06/26 17:48:43 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fdata	*initialize(void)
{
	t_fdata	*fdata;

	fdata = ft_calloc(1, sizeof(t_fdata));
	fdata->ini_t = ft_calloc(1, sizeof(struct timeval));
	set_now(fdata->ini_t);
	fdata->id = calloc(1, sizeof(pthread_t));
	return (fdata);
}

void	ph_behave(t_fdata *fdata)
{
	usleep(3500000);
	printf("%i - Vols dir?\n", elapsed(fdata->ini_t));
}

void	cleanup(t_fdata *fdata)
{
	free(fdata->id);
	free(fdata->ini_t);
	free(fdata);
}

int	main(void)
{
	t_fdata	*fdata;

	fdata = initialize();
	pthread_create(fdata->id, NULL, (void *)&ph_behave, fdata);
	pthread_join(*(fdata->id), NULL);
	cleanup(fdata);
	return (0);
}
