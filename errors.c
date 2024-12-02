/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hduflos <hduflos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:46:18 by hduflos           #+#    #+#             */
/*   Updated: 2024/12/02 16:18:04 by hduflos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//ATOL
int	is_valid(char *str)
{
	int		i;
	long	nb;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (-1);
	nb = ft_atol(str); //TODO
	if (nb < INT_MIN || nb > __INT_MAX__)
		return (-1);
	return (0);
}
int	check_duplicate(t_node **a)
{
	t_node	*cur;
	t_node	*cur2;

	cur = *a;
	while (cur)
	{
		cur2 = cur->next;
		while(cur2)
		{
			if(cur2->nb == cur->nb)
				return (1);
			cur2 = cur2->next;
		}
		cur = cur->next;
	}
	return (0);
}
