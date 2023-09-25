/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:19:50 by marvin            #+#    #+#             */
/*   Updated: 2023/05/03 17:53:09 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// philo_event //

void	philo_event(int id, char *s, t_philosopher *philo)
{
	printf("%lldms - %u - %s\n", actual_time() - philo->r_time, id, s);
}

// ft_puterror //

void	ft_puterror(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(2, &s[i++], 1);
	return ;
}

// actual time //

long long int	actual_time(void)
{
	struct timeval	current_time;
	long long int	actual_time_mili;

	gettimeofday(&current_time, NULL);
	actual_time_mili = (current_time.tv_sec * 1000) + (current_time.tv_usec
			/ 1000);
	return (actual_time_mili);
}

// ft_sleep //

void	ft_sleep(int t_eat)
{
	long long int	first_time;
	long long int	end_time;

	first_time = actual_time();
	end_time = first_time + t_eat;
	while (actual_time() < end_time)
	{
		end_time = end_time;
	}
}
