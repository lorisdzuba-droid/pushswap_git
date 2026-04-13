/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:14:39 by ldzuba            #+#    #+#             */
/*   Updated: 2025/12/17 15:40:47 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stack *stacks)
{
	t_val	*tmp;

	if (stacks->size_a < 2)
		return ;
	tmp = stacks->head_a;
	stacks->head_a = tmp->next;
	tmp->next = NULL;
	tmp->prev = stacks->tail_a;
	stacks->tail_a->next = tmp;
	stacks->tail_a = tmp;
	ft_putendl_fd("ra", 1);
}

void	ft_rotate_b(t_stack *stacks)
{
	t_val	*tmp;

	if (stacks->size_b < 2)
		return ;
	tmp = stacks->head_b;
	stacks->head_b = tmp->next;
	tmp->next = NULL;
	tmp->prev = stacks->tail_b;
	stacks->tail_b->next = tmp;
	stacks->tail_b = tmp;
	ft_putendl_fd("rb", 1);
}

void	ft_rotate_rr(t_stack *stacks)
{
	t_val	*tmp;

	if (stacks->size_a < 2 || stacks->size_b < 2)
		return ;
	tmp = stacks->head_a;
	stacks->head_a = tmp->next;
	tmp->next = NULL;
	tmp->prev = stacks->tail_a;
	stacks->tail_a->next = tmp;
	stacks->tail_a = tmp;
	tmp = stacks->head_b;
	stacks->head_b = tmp->next;
	tmp->next = NULL;
	tmp->prev = stacks->tail_b;
	stacks->tail_b->next = tmp;
	stacks->tail_b = tmp;
	ft_putendl_fd("rr", 1);
}
