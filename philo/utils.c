/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:53:40 by mbouaza           #+#    #+#             */
/*   Updated: 2023/05/03 17:53:53 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// help_input //

void	help_input(void)
{
	ft_puterror(" ____________________________________________________\n");
	ft_puterror("|                                                    |\n");
	ft_puterror("|            Please enter 4 or 5 arguments           |\n");
	ft_puterror("|____________________________________________________|\n");
	ft_puterror("|                                                    |\n");
	ft_puterror("|             [1][number_of_philosophers]            |\n");
	ft_puterror("|             [2][time_to_die]                       |\n");
	ft_puterror("|             [3][time_to_eat]                       |\n");
	ft_puterror("|             [4][time_to_sleep]                     |\n");
	ft_puterror("|             [5][Number_of_meals]                   |\n");
	ft_puterror("|____________________________________________________|\n");
}

// ft_strlen //

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// ft_atoi - utils - ft_sign //

static int	ft_sign(const char *str, int i)
{
	int	sign;
	int	num;

	num = 0;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			sign = 1;
		else if (str[i] == '-')
			sign = -1;
		num++;
		i++;
	}
	if (num > 1)
		return (42);
	return (sign);
}

// ft_atoi function //

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\v')
	{
		i++;
	}
	sign = ft_sign(str, i);
	if (sign == 42)
		return (0);
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result = result * sign;
	return (result);
}

// free_all //

void	free_all(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&philo->info.mutex_write);
	while (i < philo->info.nb_philo)
	{
		pthread_mutex_destroy(&philo->philosopher->r_fork);
		i++;
	}
	free(philo->philosopher);
	free(philo);
}
