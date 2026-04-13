/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:27:44 by ldzuba            #+#    #+#             */
/*   Updated: 2025/10/31 17:04:41 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void	to_upper_index(unsigned int i, char *c)
// {
// 	(void)i;
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - 32;
// }

// int	main(void)
// {
// 	char	str1[] = "hello";
// 	write(1, "Avant: ", 7);
// 	write(1, str1, 5);
// 	write(1, "\n", 1);
// 	ft_striteri(str1, to_upper_index);
// 	write(1, "Après: ", 7);
// 	write(1, str1, 5);
// 	write(1, "\n", 1);
// 	write(1, "Test NULL: ", 11);
// 	ft_striteri(NULL, to_upper_index);
// 	write(1, "OK\n", 3);
// 	write(1, "Test NULL func: ", 16);
// 	ft_striteri("test", NULL);
// 	write(1, "OK\n", 3);
// 	return (0);
// }
