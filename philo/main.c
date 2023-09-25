/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:45:53 by marvin            #+#    #+#             */
/*   Updated: 2023/05/03 17:48:36 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// alone //

static void	alone(t_philo *philo)
{
	printf("0ms - 1 - has taken a fork\n");
	pthread_mutex_lock(&(philo->info.mutex_write));
	ft_sleep(philo->info.t_die);
	printf("%dms - 1 - died\n", philo->info.t_die);
	pthread_mutex_unlock(&(philo->info.mutex_write));
	pthread_mutex_destroy(&(philo->info.mutex_write));
}

// main //

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	if (check_args(argc, argv))
		return (free(philo), 0);
	if (init_arg(argc, argv, philo))
		return (free(philo), 0);
	if (philo->info.nb_philo == 1)
	{
		pthread_create(&philo->thread_all, NULL, (void *)alone, (void *)philo);
		pthread_join(philo->thread_all, NULL);
		pthread_detach(philo->thread_all);
		return (free(philo), 0);
	}
	if (init_philo(philo))
		return (free(philo), 0);
	if (thread_philo(philo, philo->info.max_eat))
		return (free(philo), 0);
	free_all(philo);
	return (0);
}
