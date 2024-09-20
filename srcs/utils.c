/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:48:04 by andefern          #+#    #+#             */
/*   Updated: 2024/09/20 13:46:31 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xylophoners.h"

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

t_xylo	*ft_lstlast(t_xylo *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_xylo **lst, t_xylo *new)
{
	t_xylo	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

t_xylo	*ft_lstnew(int num)
{
	t_xylo	*new;

	new = (t_xylo *)malloc(sizeof(t_xylo));
	if (!new)
		return (NULL);
	new->num = num;
	pthread_mutex_init(&new->mallet, NULL);
	new->plays = 0;
	new->broke = 0;
	new->last_play = 0;
	new->next = NULL;
	return (new);
}

void	ft_round_list(t_xylo **xylo, t_stats *data)
{
	t_xylo	*new;
	int		i;

	i = 0;
	while (i < data->num)
	{
		new = ft_lstnew(i);
		ft_lstadd_back(xylo, new);
		new->stats = data;
		i++;
	}
	ft_lstlast(*xylo)->next = *xylo;
}
