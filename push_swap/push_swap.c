/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:19:53 by ldzuba            #+#    #+#             */
/*   Updated: 2025/12/23 13:17:31 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pushback(t_stack *stack, long val)
{
	t_val	*new;

	if (!stack)
		return (0);
	new = malloc(sizeof(t_val));
	if (!new)
		return (0);
	new->value = val;
	new->prev = stack->tail_a;
	new->index = -1;
	new->next = NULL;
	if (stack->tail_a)
		stack->tail_a->next = new;
	else
		stack->head_a = new;
	stack->tail_a = new;
	stack->size_a++;
	return (1);
}

t_stack	*ft_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head_a = NULL;
	stack->tail_a = NULL;
	stack->size_a = 0;
	stack->head_b = NULL;
	stack->tail_b = NULL;
	stack->size_b = 0;
	return (stack);
}

static t_stack	*ft_createstack(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	i = 1;
	if (argc == 2)
		i = 0;
	stack = ft_init();
	while (argv[i])
	{
		if (!ft_pushback(stack, ft_atoi(argv[i])))
		{
			ft_free_stack(&stack);
			return (NULL);
		}
		i++;
	}
	ft_index(stack);
	return (stack);
}

void	ft_sort(t_stack *stacks)
{
	if (stacks->size_a <= 5)
		ft_small_sort(stacks);
	else
		ft_big_sort(stacks);
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;

	if (argc < 2)
		return (-1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_checkargs(argc, argv);
	stacks = ft_createstack(argc, argv);
	if (!stacks)
		ft_error("Error");
	if (ft_is_sorted(stacks))
	{
		ft_free_stack(&stacks);
		if (argc == 2)
			free_split (argv);
		return (0);
	}
	ft_sort(stacks);
	ft_free_stack(&stacks);
	if (argc == 2)
		free_split (argv);
	return (0);
}
