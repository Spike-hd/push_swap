/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:26:57 by spike             #+#    #+#             */
/*   Updated: 2024/12/02 09:31:29 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(char ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

	if (ac < 2)
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	if (init_and_parse(&a, av + 1) == -1)
	{
		ft_printf("Error\n");
		return (1);
	}

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
