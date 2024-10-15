/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:46:45 by andefern          #+#    #+#             */
/*   Updated: 2024/10/15 11:55:32 by andefern         ###   ########.fr       */
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
	int					eaten_times;//times that the philo has eaten
	long				start_eating;//eating start time
	pthread_t			thread;//thread
	struct s_stats		*stats;
	struct s_philo		*next;
}						t_philo;

//ACTIONS
void	case_one(t_stats *stats);
void	thinking(t_philo *philo);
void	zzz(t_philo *philo);
void	eating(t_philo *philo);
bool	eaten_bool(t_philo *philo);

//ERASER
void	eraser(t_philo *philo, t_stats *stats);

//MAIN
void	*routine(void *args);
void	de_function(t_philo *philo);
void	*cctv(void *args);
int		sewing_kit(t_philo *philo);

//PARSE
t_stats	*stat_initializer(char **argv);
t_philo	*philo_initializer(t_stats *stats, int dni);
t_philo	*philo_list(t_stats *stats);

//TIME
long	ft_time(void);
void	ft_usleep(unsigned int ms);

//UTILS
void	bruce_s_printstring(t_philo *philo, char *str);
bool	argv_checker(int argc, char **argv);
int		ft_atoi(const char *str);

#endif