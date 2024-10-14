/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:46:45 by andefern          #+#    #+#             */
/*   Updated: 2024/10/14 11:59:15 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

# define HRED	"\033[91m"
# define HBLU	"\033[94m"
# define HGRE	"\033[92m"
# define HMAG	"\033[95m"
# define RST	"\033[0m"

typedef struct s_stats
{
	int					p_num;//number of philosophers
	int					ttd;//time to die
	int					tte;//time to eat
	int					tts;//time to sleep
	int					must_eat;//must eat
	long				start;//start
	bool				end;//finish
	bool				just_eat;
	pthread_mutex_t		print;//print mutex
}						t_stats;

typedef struct s_philo
{
	int					dni;//philosopher's id
	pthread_mutex_t		fork;//fork
	int					tenedoh; //dni tenedor
	int					eaten_times;//times that the philo has eaten
	long				start_eating;//eating start time
	pthread_t			thread;//thread
	bool				everyone;//all philos
	struct s_stats		*stats;
	struct s_philo		*next;
}						t_philo;

//ACTIONS
void	eating(t_philo *philo);
void	zinkin(t_philo *janfri);
void	bruce_s_printstring(t_philo *janfri, char *str);
void	zzz(t_philo *janfri);

//ERASER
void	eraser(t_philo *philo, t_stats *stats);

//MAIN
void	*routine(void *args);
int		sewing_kit(t_philo *janfri);

//PARSE
t_stats	*stat_initializer(char **argv);
t_philo	*argv_checker(int argc, t_stats *stats);
t_philo	*philo_initializer(t_stats *stats, int dni);
//void	parse(int argc, char const *argv[], t_stats **stats);

//TIME
long	ft_time(void);
void	ft_usleep(unsigned int ms);

//UTILS
int		ft_atoi(const char *str);
#endif