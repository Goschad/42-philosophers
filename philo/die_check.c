/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:04:16 by marvin            #+#    #+#             */
/*   Updated: 2023/05/03 17:45:18 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// eat_thread //

void	*eat_thread(void *empty)
{
	int				i;
	int				eat;
	t_philo			*philo;

	i = -1;
	eat = 1;
	philo = (t_philo *)empty;
	while (1)
	{
		while (++i < philo->info.nb_philo)
		{
			if (philo->philosopher[i].eat_nb < philo->info.max_eat)
			{
				i = 0;
				eat = 0;
				break ;
			}
		}
		if (eat == 1)
			break ;
		eat = 1;
	}
	philo->info.end = 1;
	return (NULL);
}

// dead_thread //

void	*dead_thread(void *empty)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)empty;
	if (philo->info->end != 1)
	{
		ft_sleep(philo->info->t_die);
		die_check(philo);
	}
	return (NULL);
}

// die_check //

int	die_check(t_philosopher *philo)
{
	if ((actual_time() - (philo->f_time)) >= philo->info->t_die - 10)
	{
		pthread_mutex_lock((philo->ptr_mutex_write));
		philo_event(philo->id, "died", philo);
		pthread_mutex_destroy((philo->ptr_mutex_write));
		philo->info->end = 1;
		return (-1);
	}
	return (0);
}
