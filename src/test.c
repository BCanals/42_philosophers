/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 19:11:00 by bizcru            #+#    #+#             */
/*   Updated: 2026/07/19 19:11:35 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <sys/time.h>

int	main(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	printf(" sec = %lu\n", now.tv_sec);
	printf("usec = %lu\n", now.tv_usec);
}
