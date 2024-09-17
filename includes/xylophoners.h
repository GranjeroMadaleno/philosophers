/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xylophoners.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:52:06 by andefern          #+#    #+#             */
/*   Updated: 2024/09/16 11:31:31 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XYLOPHONERS_H
# define XYLOPHONERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

//ttb == time to break
//ttp == time to play
//tts == time to study
//must_play es opcional
typedef struct s_stats
{
	int				num;
	int				ttb;
	int				ttp;
	int				tts;
	int				must_play;
	int				played;
	int				broken;
	long			tempo;
	unsigned short	vibing;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*mallet;
}				t_stats;

//mallet == fork
//sin 2 mallet no se puede tocar el xilófono
typedef struct s_xylo
{
	pthread_t		thread;
	int				num;
	int				mallet;
	int				plays;
	int				broke;
	int				left;
	long			last_play;
	t_stats			*stats;
	struct s_xylo	*next;
}					t_xylo;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

	// MAIN
int		argv_checker(int argc, char **argv, t_stats *data, t_xylo *xylo);
void	*routine(void *args);
int		sewing_kit(t_stats *data, t_xylo **xylo);

	// UTILS
int		ft_atoi(const char *str);
t_xylo	*ft_lstlast(t_xylo *lst);
void	ft_lstadd_back(t_xylo **lst, t_xylo *new);
t_xylo	*ft_lstnew(int num);
void	ft_round_list(t_xylo **xylo, t_stats *data);

	// INITIALIZER
void	initializer(t_stats *data, char **argv);
void	print_matic(t_stats *data, t_xylo *xylo);

	// TIME
long	updated_time(void);
void	overclocked_usleep(unsigned int ms);

	// ADAGIO (Adagio es un término musical que indica un tempo lento o pausado, yo lo utilizo como si fuese la muerte del filósofo)
void	adagio(t_xylo *xylo);
void	*adagio_check(void *args);

	// ERASER
void	eraser(t_xylo *xylo, t_stats *stats);

	// ACTIONS
void	ft_breaktime(t_xylo *xylo);
void	ft_playing(t_xylo *xylo);
void	ft_must_play(t_xylo *xylo);
void	ft_studying(t_xylo *xylo);
int		print_status(t_xylo *xylo, char *str);

#endif