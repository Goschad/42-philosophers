/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:58:23 by marvin            #+#    #+#             */
/*   Updated: 2023/05/03 17:43:26 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// check_digit //

static int	check_digit(char *args)
{
	int	i;
	int	number;

	i = -1;
	number = ft_atoi(args);
	while (args[++i])
	{
		if (!(args[i] >= '0' && args[i] <= '9'))
			return (ft_puterror("Error\n"), 1);
	}
	if (!(number <= 2147483647 && number > 0))
		return (ft_puterror("Error\n"), 1);
	return (0);
}

// check_args //

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (help_input(), 1);
	while (argv[i])
	{
		if (check_digit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
