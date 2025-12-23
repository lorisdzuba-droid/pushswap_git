/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:19:07 by ldzuba            #+#    #+#             */
/*   Updated: 2025/12/23 16:11:49 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	ft_error(char *str, int argc, char **argv)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
	if (argc == 2)
		free_split(argv);
	exit(0);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_duplicate(long num, char **args, int i)
{
	while (args[i])
	{
		if (num == ft_atoi(args[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_checkargs(int argc, char **argv)
{
	ssize_t		i;
	long		num;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (!ft_isnum(argv[i]))
			ft_error("Error", argc, argv);
		if (!ft_duplicate(num, argv, i + 1))
			ft_error("Error", argc, argv);
		if (ft_strlen(argv[i]) > 11)
			ft_error("Error", argc, argv);
		if (num < INT_MIN || num > INT_MAX)
			ft_error("Error", argc, argv);
		i++;
	}
}
