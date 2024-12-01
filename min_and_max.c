/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_and_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:45:52 by spike             #+#    #+#             */
/*   Updated: 2024/12/01 22:46:47 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(t_node **a)
{
	t_node *cur;
	int max;

	cur = *a;
	max = cur->nb;
	while (cur)
	{
		if (cur->nb > max)
			max = cur->nb;
		cur = cur->next;
	}
	return (max);
}

int find_min(t_node **a)
{
	t_node *cur;
	int min;

	cur = *a;
	min = __INT_MAX__;
	while (cur)
	{
		if (cur->nb < min && cur->was_min == 0)
			min = cur->nb;
		cur = cur->next;
	}
	return (min);
}
