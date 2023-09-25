/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:20:26 by marvin            #+#    #+#             */
/*   Updated: 2023/05/03 17:47:04 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// init_arg //

int	init_arg(int argc, char **argv, t_philo *philo)
{
	philo->info.nb_philo = ft_atoi(argv[1]);
	philo->info.t_die = ft_atoi(argv[2]);
	philo->info.t_eat = ft_atoi(argv[3]);
	philo->info.t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->info.max_eat = ft_atoi(argv[5]);
	else
		philo->info.max_eat = -1;
	philo->info.end = 0;
	pthread_mutex_init(&(philo->info.mutex_write), NULL);
	return (0);
}

// init_philo //

int	init_philo(t_philo *philo)
{
	int	i;

	i = -1;
	philo->philosopher = malloc(sizeof(t_philosopher) * philo->info.nb_philo);
	if (!(philo->philosopher))
		return (1);
	while (++i < philo->info.nb_philo)
	{
		philo->philosopher[i].id = i + 1;
		philo->philosopher[i].r_time = actual_time();
		philo->philosopher[i].eat_nb = 0;
		philo->philosopher[i].l_fork = NULL;
		philo->philosopher[i].ptr_mutex_write = &philo->info.mutex_write;
		if (pthread_mutex_init(&philo->philosopher[i].r_fork, NULL) != 0)
			return (free(philo->philosopher), 1);
		if (philo->info.nb_philo == 1)
			return (0);
		if (i == (philo->info.nb_philo - 1))
			philo->philosopher[i].l_fork = &philo->philosopher[0].r_fork;
		else
			philo->philosopher[i].l_fork = &philo->philosopher[i + 1].r_fork;
	}
	return (0);
}
