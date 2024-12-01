/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:37:59 by spike             #+#    #+#             */
/*   Updated: 2024/12/01 22:46:49 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	check_duplicate(t_node **a)
{
	t_node	*cur;
	t_node	*cur2;

	cur = *a;
	while (cur)
	{
		cur2 = cur->next;
		while(cur2)
		{
			if(cur2->nb == cur->nb)
				return (1);
			cur2 = cur2->next;
		}
		cur = cur->next;
	}
	return (0);
}

void	init_nodes(t_node **a, int value)
{
	t_node	*new_node;
	t_node	*cur;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->nb = value;
	new_node->was_min = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*a == NULL)
		*a = new_node;
	else
	{
		cur = *a;
		while (cur->next)
			cur = cur->next;
		cur->next = new_node;
		new_node->prev = cur;
	}
}

int	init_size_and_median(t_node **a) // devrais je egalement indiquer le min et max ?
{
	t_node	*cur;
	int		count;

	cur = *a;
	count = 0;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	cur = *a;
	while (cur->next)
	{
		cur->average = count / 2; // quid des floats ?
		cur = cur->next;
	}

	return (count);
}

void init_simplified_nb(t_node **a, int size)
{
	t_node *cur;
	int min;
	int i;

	cur = *a;
	i = 0;
	while (i < size)
	{
		min = find_min(&a);
		while (cur)
		{
			if (cur->nb == min && cur->was_min != 1)
			{
				cur->simplified_nb = i;
				cur->was_min = 1;
				break;
			}
			cur = cur->next;
		}
		i++;
	}
}

int	init_and_parse(t_node **a, char **av)
{
	t_node	*cur;
	int		i;
	int		size;

	i = 0;
	while (av[i])
	{
		init_nodes(&a, ft_aoi(av[i])); // <= il faut verificer chaque atoi
		i++;
	}
	size = init_size_and_median(&a); // c'est bof comme fonction
	if (check_duplicate(&a))
		return (-1);
	init_simplified_nb(&a, size);
	return (size);
	// nouvelle fonction bool pour min / max ?
}
