/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:08:22 by spike             #+#    #+#             */
/*   Updated: 2024/11/27 18:46:07 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_node **x)
{
	t_node	*cur;
	t_node	*new_tail;
	t_node	*new_head;

	if (!x || !*x || !(*x)->next)
		return ;

	new_tail = *x;
	cur = *x;
	new_head = (*x)->next;

	new_head->prev = NULL;
	while (cur->next)
		cur = cur->next;

	new_tail->prev = cur;
	new_tail->next = NULL;
	cur->next = new_tail;

	*x = new_head;
}

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
