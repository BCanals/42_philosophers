/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:50:04 by bizcru            #+#    #+#             */
/*   Updated: 2026/09/07 21:41:09 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <errno.h>

# define EAT 0
# define SLEEP 1
# define THINK 2
# define DELAY 3
# define PH_STOP 4

# define LIVE 1
# define STOP 0

# define FREE 0
# define TAKEN 1

# define ONCE 1
# define LOOP 0

typedef struct s_philo	t_philo;

typedef void			(*t_action)(t_philo *);

typedef struct s_philo
{
	int				id;
	int				fork_a;
	int				fork_b;
	struct timeval	*ate;
	pthread_mutex_t	ate_m;
	int				eaten;
	int				action;
	pthread_mutex_t	action_m;
	t_action		acts[4];
	struct s_table	*table;

}				t_philo;

typedef struct s_table
{
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				status;
	pthread_mutex_t	status_m;
	pthread_t		*ids;
	pthread_t		checker;
	struct timeval	*ini_t;
	t_philo			**philos;
	pthread_mutex_t	start;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
}				t_table;

typedef pthread_mutex_t	t_mut;

void			*ft_calloc(size_t nmemb, size_t size);

void			isleep(t_philo *philo, int time);
unsigned int	elapsed(t_philo *philo);
long			time_diff(struct timeval *start, struct timeval *end);
void			time_add(struct timeval *time, int ms);
int				get_my_action(t_philo *me);
int				is_sim_live(t_table *table);
void			my_printf(char *msg, int elaps, t_philo *philo);

int				starved(t_philo *philo, struct timeval *now);
void			cleanup(t_table *table);

t_table			*create_table(int params[]);

void			*ph_behave(void *me);
void			ft_sleep(t_philo *me);
void			ft_think(t_philo *me);
void			ft_eat(t_philo *me);
void			ft_delay(t_philo *me);

void			ft_checker(t_table *table);

#endif
