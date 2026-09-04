/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:13:14 by bcanals-          #+#    #+#             */
/*   Updated: 2026/09/04 21:29:46 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		*ptr = c;
		i++;
		ptr++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rtrn;

	rtrn = malloc(nmemb * size);
	if (rtrn == NULL)
		return (NULL);
	ft_memset(rtrn, 0, nmemb * size);
	return (rtrn);
}

void	cleanup(t_table *table)
{
	int	i;

	if (!table)
		return ;
	i = -1;
	while (table->philos[++i])
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos_m[i]);
		pthread_mutex_destroy(&table->philos[i]->ate_m);
		pthread_mutex_destroy(&table->philos[i]->action_m);
		free(table->philos[i]->ate);
		free(table->philos[i]);
	}
	pthread_mutex_destroy(&table->start);
	pthread_mutex_destroy(&table->status_m);
	pthread_mutex_destroy(&table->print);
	free(table->ids);
	free(table->ini_t);
	free(table->forks);
	free(table->forks_s);
	free(table->philos_m);
	free(table->philos);
	free(table);
}
