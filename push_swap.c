/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:26:57 by spike             #+#    #+#             */
/*   Updated: 2024/12/04 21:13:37 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void clear_stack(t_node **stack)
{
	t_node *current;
	t_node *next;

	if (!stack || !*stack)
		return;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	free_split(char **split)
{
	int i = 0;

	while (split[i])
		free(split[i++]);
	free(split);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		size;
	char	**split_av;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	if (ac == 2)
	{
		split_av = ft_split(av[1], ' ');
		if (!split_av)
			return (print_error());
		size = init_and_parse(&a, split_av);
		free_split(split_av);
	}
	else
		size = init_and_parse(&a, av + 1);
	if (!size)
		return (print_error());
	if (size > 1)
		sorting_all(&a, &b, size);
	clear_stack(&a);
	return (0);
}
