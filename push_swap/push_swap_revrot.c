/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_revrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:51:47 by ldzuba            #+#    #+#             */
/*   Updated: 2025/12/19 14:15:15 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rot_a(t_stack *stacks)
{
	t_val	*tmp;

	tmp = stacks->tail_a;
	stacks->tail_a = tmp->prev;
	stacks->tail_a->next = NULL;
	tmp->next = stacks->head_a;
	stacks->head_a->prev = tmp;
	stacks->head_a = tmp;
	stacks->head_a->prev = NULL;
	ft_putendl_fd("rra", 1);
}

void	ft_rev_rot_b(t_stack *stacks)
{
	t_val	*tmp;

	tmp = stacks->tail_b;
	stacks->tail_b = tmp->prev;
	stacks->tail_b->next = NULL;
	tmp->next = stacks->head_b;
	tmp->prev = NULL;
	stacks->head_b->prev = tmp;
	stacks->head_b = tmp;
	ft_putendl_fd("rrb", 1);
}

void	ft_rev_rot_rrr(t_stack *stacks)
{
	t_val	*tmp;

	tmp = stacks->tail_a;
	stacks->tail_a = tmp->prev;
	stacks->tail_a->next = NULL;
	tmp->next = stacks->head_a;
	stacks->head_a->prev = tmp;
	stacks->head_a = tmp;
	tmp->prev = NULL;
	tmp = stacks->tail_b;
	stacks->tail_b = tmp->prev;
	stacks->tail_b->next = NULL;
	tmp->next = stacks->head_b;
	stacks->head_b->prev = tmp;
	stacks->head_b = tmp;
	tmp->prev = NULL;
	ft_putendl_fd("rrr", 1);
}