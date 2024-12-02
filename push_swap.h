/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:35:11 by spike             #+#    #+#             */
/*   Updated: 2024/12/01 16:52:39 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				nb;
	int				simplified_nb;
	int				was_min;
	int				average;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int find_max(t_node **a);
int find_min(t_node **a);

#endif
