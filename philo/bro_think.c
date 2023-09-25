/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bro_think.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:42:00 by marvin            #+#    #+#             */
/*   Updated: 2023/05/03 17:32:20 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	bro_thinking(t_philosopher *philo)
{
	pthread_mutex_lock((philo->ptr_mutex_write));
	philo_event(philo->id, "is thinking", philo);
	pthread_mutex_unlock((philo->ptr_mutex_write));
}

int	bro_think(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->r_fork));
	pthread_mutex_lock((philo->ptr_mutex_write));
	philo_event(philo->id, "has taken a fork", philo);
	pthread_mutex_unlock((philo->ptr_mutex_write));
	pthread_mutex_lock((philo->l_fork));
	pthread_mutex_lock((philo->ptr_mutex_write));
	philo_event(philo->id, "has taken a fork", philo);
	pthread_mutex_unlock((philo->ptr_mutex_write));
	pthread_mutex_lock((philo->ptr_mutex_write));
	philo_event(philo->id, "is eating", philo);
	pthread_mutex_unlock((philo->ptr_mutex_write));
	philo->f_time = actual_time();
	ft_sleep(philo->info->t_eat);
	if (philo->eat_nb != 2147483647)
		philo->eat_nb += 1;
	pthread_mutex_unlock(&(philo->r_fork));
	pthread_mutex_unlock((philo->l_fork));
	pthread_mutex_lock((philo->ptr_mutex_write));
	philo_event(philo->id, "is sleeping", philo);
	pthread_mutex_unlock((philo->ptr_mutex_write));
	ft_sleep(philo->info->t_sleep);
	bro_thinking(philo);
	return (0);
}
