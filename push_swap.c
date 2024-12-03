/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:26:57 by spike             #+#    #+#             */
/*   Updated: 2024/12/02 21:49:02 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_node *stack) // a retirer
{
    t_node *current;

    if (!stack)
    {
        printf("La pile est vide.\n");
        return;
    }

    current = stack;
    while (current)
    {
        printf("nb: %d, simplified_nb: %d\n", current->nb, current->simplified_nb);
        current = current->next;
    }
}

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
	radix_sort(&a, &b, size);
	print_stack(a); // a retirer
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}

/*
on a init la node A
elle contient :
	- son nombre
	- la moyenne (la mediane serait mieux mais je ne sais pas comment faire)
	- sa taille totale

Il faut maintenant creer l'algo de radix sort.

Il faut maintenant connecter toute les fonctions ensemble + reflechir pour les moins de 100 si radix sort n'est pas opti.
Solution :
	- Nouvel algo ? => tri par insertion / quick sort ?
	- optimisation de radix sort ?

*/
