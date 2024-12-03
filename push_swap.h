/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:35:11 by spike             #+#    #+#             */
/*   Updated: 2024/12/02 21:48:57 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // Pour printf DELETE


# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/_libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct s_node
{
	int				nb;
	int				simplified_nb;
	int				was_min;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

		/* UTILS */
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

		/* ERRORS */
int		print_error(void);
int		is_valid(char *str);
int	check_duplicate(t_node **a);

int		init_and_parse(t_node **a, char **av);
void	radix_sort(t_node **a, t_node **b, int max);

int		find_max(t_node **a);
int		find_min(t_node **a);



void print_stack(t_node *stack); // delete
#endif
