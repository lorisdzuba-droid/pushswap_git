/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:33:50 by ldzuba            #+#    #+#             */
/*   Updated: 2025/12/23 14:16:02 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stacks)
{
	t_val	*tmp;

	tmp = stacks->head_a;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_three(t_stack *stacks)
{
	int	first;
	int	second;
	int	third;

	first = stacks->head_a->value;
	second = stacks->head_a->next->value;
	third = stacks->tail_a->value;
	if (first > second && second > third)
	{
		ft_swap_a(stacks);
		ft_rev_rot_a(stacks);
	}
	else if (first > second && second < third && first > third)
		ft_rotate_a(stacks);
	else if (first > second && second < third)
		ft_swap_a(stacks);
	else if (first < second && second > third && first > third)
		ft_rev_rot_a(stacks);
	else if (first < second && second > third)
	{
		ft_swap_a(stacks);
		ft_rotate_a(stacks);
	}
}

static void	sort_four(t_stack *stacks)
{
	int	distance;

	distance = get_distance(stacks, get_min(stacks, -1));
	if (distance == 1)
		ft_rotate_a(stacks);
	else if (distance == 2)
	{
		ft_rotate_a(stacks);
		ft_rotate_a(stacks);
	}
	else if (distance == 3)
		ft_rev_rot_a(stacks);
	if (ft_is_sorted(stacks))
		return ;
	ft_push_b(stacks);
	sort_three(stacks);
	ft_push_a(stacks);
}

void	sort_five(t_stack *stacks)
{
	int	distance;

	distance = get_distance(stacks, get_min(stacks, -1));
	if (distance == 1)
		ft_rotate_a(stacks);
	else if (distance == 2)
	{
		ft_rotate_a(stacks);
		ft_rotate_a(stacks);
	}
	else if (distance == 3)
	{
		ft_rev_rot_a(stacks);
		ft_rev_rot_a(stacks);
	}
	else if (distance == 4)
		ft_rev_rot_a(stacks);
	if (ft_is_sorted(stacks))
		return ;
	ft_push_b(stacks);
	sort_four(stacks);
	ft_push_a(stacks);
}

void	ft_small_sort(t_stack *stacks)
{
	if (ft_is_sorted(stacks) || stacks->size_a < 2)
		return ;
	if (stacks->size_a == 2)
		ft_swap_a(stacks);
	else if (stacks->size_a == 3)
		sort_three(stacks);
	else if (stacks->size_a == 4)
		sort_four(stacks);
	else if (stacks->size_a == 5)
		sort_five(stacks);
}
