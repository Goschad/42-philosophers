/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 02:49:41 by marvin            #+#    #+#             */
/*   Updated: 2023/05/03 17:51:34 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// thread //

void	*thread(void *empty)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)empty;
	philo->f_time = actual_time();
	if (philo->id % 2 == 0)
		ft_sleep(philo->info->t_eat / 10);
	while (philo->info->end == 0)
	{
		if (pthread_create(&philo->philo_dead, NULL, &dead_thread,
				(void *)philo) != 0)
			return (NULL);
		if (bro_think(philo) == -1)
			break ;
		pthread_detach(philo->philo_dead);
	}
	return (NULL);
}

// thread philo //

int	thread_philo(t_philo *philo, int max_eat)
{
	int	i;

	i = 0;
	while (i < philo->info.nb_philo)
	{
		philo->philosopher[i].info = &philo->info;
		if (pthread_create(&philo->philosopher[i].philo_thread, NULL, &thread,
				(void *)&philo->philosopher[i]) != 0)
			return (1);
		pthread_detach(philo->philosopher[i].philo_thread);
		i++;
	}
	if (max_eat != -1)
	{
		if (pthread_create(&philo->thread_all, NULL, &eat_thread,
				(void *)philo) != 0)
			return (1);
		pthread_detach(philo->thread_all);
	}
	while (philo->info.end != 1)
		;
	return (0);
}
