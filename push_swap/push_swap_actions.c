/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:04:45 by ldzuba            #+#    #+#             */
/*   Updated: 2025/12/22 13:03:22 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack *stacks)
{
	t_val	*tmp;

	if (stacks->size_a < 2)
		return ;
	tmp = stacks->head_a;
	stacks->head_a = tmp ->next;
	tmp->prev = stacks->head_a;
	tmp->next = stacks->head_a->next;
	if (tmp->next)
		tmp->next->prev = tmp;
	stacks->head_a->next = tmp;
	stacks->head_a->prev = NULL;
	if (stacks->size_a == 2)
		stacks->tail_a = tmp;
	ft_putendl_fd("sa", 1);
}

void	ft_swap_b(t_stack *stacks)
{
	t_val	*tmp;

	if (stacks->size_b < 2)
		return ;
	tmp = stacks->head_b;
	stacks->head_b = tmp ->next;
	tmp->prev = stacks->head_b;
	tmp->next = stacks->head_b->next;
	if (tmp->next)
		tmp->next->prev = tmp;
	stacks->head_b->next = tmp;
	stacks->head_b->prev = NULL;
	if (stacks->size_b == 2)
		stacks->tail_b = tmp;
	ft_putendl_fd("sb", 1);
}

void	ft_push_b(t_stack *stacks)
{
	t_val	*tmp_a;
	t_val	*tmp_b;

	if (stacks->size_a < 1)
		return ;
	tmp_a = stacks->head_a;
	tmp_b = stacks->head_b;
	stacks->head_a = tmp_a->next;
	if (stacks->head_a)
		stacks->head_a->prev = NULL;
	else
		stacks->tail_a = NULL;
	tmp_a->next = tmp_b;
	if (tmp_b)
		tmp_b->prev = tmp_a;
	stacks->head_b = tmp_a;
	stacks->size_a--;
	stacks->size_b++;
	if (stacks->size_b == 1)
		stacks->tail_b = tmp_a;
	ft_putendl_fd("pb", 1);
}

void	ft_push_a(t_stack *stacks)
{
	t_val	*tmp_a;
	t_val	*tmp_b;

	if (stacks->size_b < 1)
		return ;
	tmp_a = stacks->head_a;
	tmp_b = stacks->head_b;
	stacks->head_b = tmp_b->next;
	if (stacks->head_b)
		stacks->head_b->prev = NULL;
	else
		stacks->tail_b = NULL;
	tmp_b->next = tmp_a;
	if (tmp_a)
		tmp_a->prev = tmp_b;
	stacks->head_a = tmp_b;
	stacks->size_b--;
	stacks->size_a++;
	if (stacks->size_a == 1)
		stacks->tail_a = tmp_b;
	ft_putendl_fd("pa", 1);
}
