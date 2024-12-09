/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:46:18 by hduflos           #+#    #+#             */
/*   Updated: 2024/12/10 00:12:26 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long result;
	int sign;
	int i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * sign);
}
int is_valid(char *str)
{
	int		i;
	long	nb;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!str[i])
		return (0);
	if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (0);
	nb = ft_atol(str);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	return (1);
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

int	print_error(t_node **a)
{
	clear_stack(&a);
	ft_printf("Error\n");
	return (1);
}

int	already_sorted(t_node **a, int size)
{
	t_node	*cur;

	if (size == 1)
		return (1);

	cur = *a;
	while (cur->next)
	{
		if (cur->next->simplified_nb > cur->simplified_nb)
			return (0);
		cur = cur->next;
	}
	return (1);
}
