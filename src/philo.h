/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:50:04 by bizcru            #+#    #+#             */
/*   Updated: 2025/06/26 22:36:50 by bcanals-         ###   ########.fr       */
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
	int				name;
	struct timeval	*my_time;
}				t_philo;

typedef struct s_fdata
{
	pthread_t		*id;
	struct timeval	*ini_t;
	t_philo			**philos;
}				t_fdata;

typedef	pthread_mutex_t t_mut;

void			*ft_calloc(size_t nmemb, size_t size);
unsigned int	elapsed(struct timeval *ini);
void			set_now(struct timeval *now);

#endif
