/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:31:13 by mbouaza           #+#    #+#             */
/*   Updated: 2023/05/03 17:49:59 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* ----- include ----- */

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/* ----- struct ----- */

// info struct //

typedef struct s_info
{
	unsigned int	nb_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	int				max_eat;
	int				end;
	pthread_mutex_t	mutex_write;
}					t_info;

// philo struct //

typedef struct s_philosopher
{
	unsigned int	id;
	int				eat_nb;
	long long int	f_time;
	long long int	r_time;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*ptr_mutex_write;
	pthread_t		philo_thread;
	pthread_t		philo_dead;
	t_info			*info;
}					t_philosopher;

// info + philo struct //

typedef struct s_philo
{
	t_info			info;
	t_philosopher	*philosopher;
	pthread_t		thread_all;
}					t_philo;

/* ----- function ----- */

// check //

int				check_args(int argc, char **argv);

// init //

int				init_philo(t_philo *philo);
int				init_arg(int argc, char **argv, t_philo *philo);

// thread_start //

void			*thread(void *empty);
int				thread_philo(t_philo *philo, int max_eat);

// bro_think //

int				bro_think(t_philosopher *philo);

// time //

void			ft_puterror(char *s);
void			philo_event(int id, char *s, t_philosopher *philo);
long long int	actual_time(void);
void			ft_sleep(int t_eat);

// die_check //

void			*dead_thread(void *empty);
int				die_check(t_philosopher *philo);
void			*eat_thread(void *empty);

// utils //

void			help_input(void);
int				ft_strlen(char *s);
int				ft_atoi(const char *str);
void			free_all(t_philo *philo);

/* ----- end ----- */

#endif
