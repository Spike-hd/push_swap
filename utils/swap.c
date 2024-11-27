/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:15:33 by spike             #+#    #+#             */
/*   Updated: 2024/11/27 18:46:28 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void swap(t_node **x)
{
	t_node	*cur1;
	t_node	*cur2;

	if (!x || !*x)
		return ;

	cur1 = *x;
	cur2 = cur1->next;

	if (!cur2)
		return;

	cur1->next = cur2->next;
	if (cur2->next)
		cur2->next->prev = cur1;

	cur2->prev = cur1->prev;
	if (cur1->prev)
		cur1->prev->next = cur2;

	cur2->next = cur1;
	cur1->prev = cur2;

    *x = cur2;
}

void	sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
