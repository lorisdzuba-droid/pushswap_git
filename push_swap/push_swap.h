/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:49:23 by ldzuba            #+#    #+#             */
/*   Updated: 2025/12/17 15:40:59 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_val
{
	int				value;
	int				index;
	struct s_val	*prev;
	struct s_val	*next;
}	t_val;

typedef struct s_stack
{
	t_val	*head_a;
	t_val	*tail_a;
	int		size_a;
	t_val	*head_b;
	t_val	*tail_b;
	int		size_b;

}	t_stack;

void	ft_checkargs(int argc, char **argv);
char	**ft_split(char const *s, char c);
void	ft_free_stack(t_stack **sta);
void	ft_free(char **str);
void	ft_error(char *str);
void	free_split(char **str);
void	ft_swap_a(t_stack *stacks);
void	ft_push_b(t_stack *stacks);
void	ft_push_a(t_stack *stacks);
void	ft_swap_b(t_stack *stacks);
void	ft_rotate_a(t_stack *stacks);
void	ft_rotate_b(t_stack *stacks);
void	ft_rotate_rr(t_stack *stacks);
#endif