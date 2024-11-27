/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:20:45 by spike             #+#    #+#             */
/*   Updated: 2024/11/27 18:45:18 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_node **x)
{
	t_node	*head;
	t_node	*tail;

	if (!x || !*x || !(*x)->next)
		return ;

	head = *x;
	tail = head;
	while (tail->next)
		tail = tail->next;

	tail->prev->next = NULL;
	tail->next = head;
	tail->prev = NULL;
	head->prev = tail;

	*x = tail;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
