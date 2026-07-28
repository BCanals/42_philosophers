/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:50:04 by bizcru            #+#    #+#             */
/*   Updated: 2026/07/28 17:05:53 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define EAT 0
# define SLEEP 1
# define THINK 2

# define LIVE 1
# define STOP 0

typedef struct s_philo t_philo;

typedef void (*t_action)(t_philo *);

typedef struct s_philo
{
	int				id;
	struct timeval	*my_time;
	int				action;
	t_action		acts[3];
	struct s_table	*table;

}				t_philo;

typedef struct s_table
{
	pthread_t		*ids;
	int				philos_num;
	int				status;
	struct timeval	*ini_t;
	t_philo			**philos;
	pthread_mutex_t	start;
	pthread_mutex_t	*forks;
}				t_table;

typedef pthread_mutex_t	t_mut;

void			*ft_calloc(size_t nmemb, size_t size);
unsigned int	elapsed(struct timeval *ini);
void			cleanup(t_table *table);

t_table			*create_table(int philos_num);

void			ph_behave(t_philo *me);
void			ft_sleep(t_philo *me);
void			ft_think(t_philo *me);
void			ft_eat(t_philo *me);

#endif
