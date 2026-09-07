/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:19:24 by bizcru            #+#    #+#             */
/*   Updated: 2026/09/07 21:37:03 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parser(int argc, char **argv, int params[]);
static int	is_only_nums(char *str);
static int	my_atoi(char *str);
static void	set_philos_start_time(t_table *table);

int	main(int argc, char **argv)
{
	t_table	*table;
	int		i;
	int		params[5];

	if (!parser(argc, argv, params))
		return (1);
	table = create_table(params);
	if (table == NULL)
		return (1);
	i = -1;
	while (++i < params[0])
		pthread_create(&table->ids[i], NULL, ph_behave,
			table->philos[i]);
	gettimeofday(table->ini_t, NULL);
	set_philos_start_time(table);
	pthread_mutex_unlock(&table->start);
	pthread_create(&table->checker, NULL, (void *)&ft_checker, table);
	pthread_join(table->checker, NULL);
	i = -1;
	while (++i < params[0])
		pthread_join(table->ids[i], NULL);
	cleanup(table);
	return (0);
}

int	parser(int argc, char **argv, int params[])
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of args.\n"
			"Usage: %s number_of_philosophers time_to_die time_to_eat "
			"time_to_sleep [number_of_times_each_philosopher_must_eat]\n\n"
			"Note: all times are taken in miliseconds", argv[0]);
		return (0);
	}
	params[4] = 0;
	while (--argc > 0)
	{
		if (!is_only_nums(argv[argc]))
		{
			printf("Error: the args must be numerical chars only.\n");
			return (0);
		}
		params[argc - 1] = my_atoi(argv[argc]);
		if (!params[argc - 1] && errno == ERANGE)
		{
			printf("Error: Overflow detected while parsing args.\n");
			return (0);
		}
	}
	return (1);
}

int	is_only_nums(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	my_atoi(char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return (ret);
}

void	set_philos_start_time(t_table *table)
{
	int		i;
	t_philo	*me;

	i = -1;
	while (++i < table->philos_num)
	{
		me = table->philos[i];
		*(me->ate) = *(table->ini_t);
	}
}
