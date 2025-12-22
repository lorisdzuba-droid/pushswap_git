/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sortbig.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:14:24 by ldzuba            #+#    #+#             */
/*   Updated: 2025/12/22 13:58:33 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_stack *stacks)
{
	t_val	*tmp;
	int		max;
	int		bits;

	tmp = stacks->head_a;
	max = tmp->index;
	bits = 0;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_big_sort(t_stack	*stacks)
{
	t_val	*tmp;
	int		i;
	int		j;
	int		size;
	int		max;

	i = 0;
	tmp = stacks->head_a;
	max = ft_max(stacks);
	size = stacks->size_a;
	while (i < max)
	{
		j = 0;
		while (j++ < size)
		{
			tmp = stacks->head_a;
			if (((tmp->index >> i) & 1) == 1)
				ft_rotate_a(stacks);
			else
				ft_push_b(stacks);
		}
		while (stacks->size_b != 0)
			ft_push_a(stacks);
		i++;
	}
}
