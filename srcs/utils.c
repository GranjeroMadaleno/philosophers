/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:48:08 by andefern          #+#    #+#             */
/*   Updated: 2024/10/07 10:30:26 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 1;
	n = 0;
	while (str[i] == '\n' || str[i] == '\f' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == ' ' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + str[i] - '0';
		i++;
	}
	return (n * j);
}
/*

t_philo	*ft_lstnew(int dni)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	if (node == NULL)
		return (NULL);
	node->dni = dni;
	node->next = NULL;
	return (node);
}

t_philo	*ft_lstlast(t_philo *lst)
{
	while (lst->next)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*final;

	if (!(*lst))
		*lst = new;
	else
	{
		final = ft_lstlast(*lst);
		final->next = new;
	}
}

void	ft_create_list(t_philo **philo, t_stats *stats)
{
	int		i;

	i = 0;
	while (i <= stats->p_num)
	{
		ft_lstadd_back(philo, ft_lstnew(i));
		i++;
	}
	ft_lstlast(*philo)->next = *philo;
}
*/