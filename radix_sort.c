/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:32:03 by spike             #+#    #+#             */
/*   Updated: 2024/12/02 19:43:58 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_bit(t_node **a, t_node **b, int bit, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if ((((*a)->simplified_nb >> bit) & 1) == 1)
			pb(a, b);
		else
			ra(a);
		j++;
	}
}

void	radix_sort(t_node **a, t_node **b, int max)
{
	int		nb_bits;
	int		i;
	int		size;

	nb_bits = 0;
	size = max;
	while (max)
	{
		nb_bits++;
		max >>= 1;
	}
	i = 0;
	while (i < nb_bits)
	{
		process_bit(a, b, i, size);
		while (*b)
			pa(a, b);
		i++;
	}
}
