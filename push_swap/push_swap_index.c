/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:18:36 by ldzuba            #+#    #+#             */
/*   Updated: 2025/12/19 16:48:33 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index(t_stack *stacks, int val)
{
	ssize_t	index;
	t_val	*tmp;

	index = 0;
	tmp = stacks->head_a;
	while (tmp)
	{
		if (tmp->value < val)
			index++;
		tmp = tmp->next;
	}
	return (index);
}

void	ft_index(t_stack *stacks)
{
	int		val;
	t_val	*tmp;

	tmp = stacks->head_a;
	if (!tmp->next)
		return ;
	while (tmp)
	{
		val = tmp->value;
		tmp->index = ft_find_index(stacks, val);
		tmp = tmp->next;
	}
}

int	get_min(t_stack *stacks, int val)
{
	t_val	*tmp;
	int		min;

	tmp = stacks->head_a;
	min = tmp->index;
	while (tmp->next)
	{
		tmp = tmp->next;
		if ((tmp->index < min) && tmp->index != val)
			min = tmp->index;
	}
	return (min);
}
