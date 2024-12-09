/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:35:11 by spike             #+#    #+#             */
/*   Updated: 2024/12/10 00:11:49 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

void clear_stack(t_node **stack);
int		print_error(t_node **a);
int		is_valid(char *str);
int		check_duplicate(t_node **a);
int		already_sorted(t_node **a, int size);

int		init_and_parse(t_node **a, char **av);
void	radix_sort(t_node **a, t_node **b, int max);

int		find_max(t_node **a);
int		find_min(t_node **a);
int		get_size(t_node *stack);

void	sorting_three(t_node **a);
void	sorting_all(t_node **a, t_node **b, int size);

#endif
