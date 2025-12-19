/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:55:40 by ldzuba            #+#    #+#             */
/*   Updated: 2025/12/19 16:59:31 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_distance(t_stack *stacks, int index)
{
	t_val	*head;
	int		distance;

	distance = 0;
	head = stacks->head_a;
	while (head)
	{
		if (head->index == index)
			return (distance);
		distance++;
		head = head->next;
	}
	return (distance);
}
