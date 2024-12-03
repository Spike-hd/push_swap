/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:37:59 by spike             #+#    #+#             */
/*   Updated: 2024/12/02 22:12:48 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_nodes(t_node **a, int value)
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

static void	init_simplified_nb(t_node **a, int size)
{
	t_node *cur;
	int 	min;

	while (size)
	{
		min = find_min(a);
		cur = *a;
		while (cur)
		{
			if (cur->nb == min && cur->was_min != 1)
			{
				cur->simplified_nb = size;
				cur->was_min = 1;
				break;
			}
			cur = cur->next;
		}
		size--;
	}
}

int	init_and_parse(t_node **a, char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		//if (is_valid(av[i]))
			init_nodes(a, ft_atoi(av[i]));
		//else
			//return (0);
		i++;
	}
	if (check_duplicate(a))
		return (0);
	init_simplified_nb(a, i);

	return (i);
}
