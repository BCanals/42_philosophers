/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:50:04 by bizcru            #+#    #+#             */
/*   Updated: 2026/07/27 14:18:02 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	struct timeval	*my_time;
	struct s_table	*table;

}				t_philo;

typedef struct s_table
{
	pthread_t		*ids;
	int				philos_num;
	struct timeval	*ini_t;
	t_philo			**philos;
	pthread_mutex_t	start;
	pthread_mutex_t	*forks;
}				t_table;

typedef pthread_mutex_t	t_mut;

void			*ft_calloc(size_t nmemb, size_t size);
unsigned int	elapsed(struct timeval *ini);
void			cleanup(t_table *table);

void			ph_behave(t_philo *me);

#endif
