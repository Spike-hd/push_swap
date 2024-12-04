/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:32:03 by spike             #+#    #+#             */
/*   Updated: 2024/12/04 21:24:34 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_bit(t_node **a, t_node **b, int bit, int size)
{
	while (size)
	{
		if ((((*a)->simplified_nb >> bit) & 1) == 1)
			pb(a, b);
		else
			ra(a);
		size--;
	}
	return ;
}

void	process_b(t_node **a, t_node **b, int next_bit, int size)
{
	while (size)
	{
		if ((((*b)->simplified_nb >> next_bit) & 1) == 1)
			rb(b);
		else
			pa(a, b);
		size--;
	}
	return ;
}


void	radix_sort(t_node **a, t_node **b, int max)
{
	int	nb_bits;
	int	i;
	int	size;

	nb_bits = 0;
	while (max)
	{
		nb_bits++;
		max >>= 1;
	}
	i = 0;
	while (i < nb_bits)
	{
		size = get_size(*a);
		process_bit(a, b, i, size);
		size = get_size(*b);
		if (i + 1 < nb_bits)
			process_b(a, b, i + 1, size);
		else
		{
			while (*b)
				pa(a, b);
		}
		i++;
	}
}

