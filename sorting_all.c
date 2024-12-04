/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:35:43 by spike             #+#    #+#             */
/*   Updated: 2024/12/04 21:31:31 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_three(t_node **a)
{
	int	max;

	max = find_max(a);
	if ((*a)->nb == max)
		ra(a);
	else if ((*a)->next->nb == max)
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}
void	final_sort(t_node **a, t_node **b, int to_move)
{
	sorting_three(a);
	while (*b)
	{
		if ((*b)->next)
		{
			if ((*b)->nb < (*b)->next->nb)
				sb(b);
		}
		pa(a, b);
	}
	while (to_move)
	{
		ra(a);
		to_move--;
	}
}

void	sorting_five(t_node **a, t_node **b, int size)
{
	int		max;
	int		to_send;
	int		to_move;

	to_send = size - 3;
	to_move = to_send;
	while (to_send)
	{
		max = find_max(a);
		while ((*a)->nb != max)
			ra(a);
		pb(a, b);
		to_send--;
	}
	final_sort(a, b, to_move);
}


void	sorting_all(t_node **a, t_node **b, int size)
{
	if (size == 2)
		ra(a);
	else if (size == 3)
		sorting_three(a);
	else if (size <= 5)
		sorting_five(a, b, size);
	else
		radix_sort(a, b, size);
}
