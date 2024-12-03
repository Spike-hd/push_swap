/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:48:26 by spike             #+#    #+#             */
/*   Updated: 2024/12/02 19:49:50 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_node **x, t_node **y) // je push y dans x
{
	t_node	*cur1;
	t_node	*old_head_x;

	if (!y || !*y)
		return ;

	cur1 = *y;
	old_head_x = *x;

	if (cur1->next)
	{
		*y = cur1->next;
		(*y)->prev = NULL;
	}
	else
		*y = NULL;

	if (old_head_x)
		old_head_x->prev = cur1;
	cur1->next = old_head_x;
	cur1->prev = NULL;
	*x = cur1;

}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
