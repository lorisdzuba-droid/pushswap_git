/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:46:47 by ldzuba            #+#    #+#             */
/*   Updated: 2025/12/17 16:25:44 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **sta)
{
	t_val	*tmp;
	t_val	*next;

	if (!sta)
		return ;
	tmp = (*sta)->head_a;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	tmp = (*sta)->head_b;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*sta);
	*sta = NULL;
}

void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
