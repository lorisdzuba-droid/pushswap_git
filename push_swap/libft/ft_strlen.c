/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:09:00 by ldzuba            #+#    #+#             */
/*   Updated: 2025/10/28 12:08:38 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
	{
		count++;
	}
	return (count);
}
/*int	main(void)
{
	const char *s;

	s = "  63 51 \n gsdserv set s'[p";

	printf("%zu\n", ft_strlen(s));
	//printf("%lu", strlen(s));
	return (0);
}*/
