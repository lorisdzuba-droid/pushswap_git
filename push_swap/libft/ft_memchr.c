/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:24:36 by ldzuba            #+#    #+#             */
/*   Updated: 2025/10/28 12:08:38 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sc;
	size_t				i;

	i = 0;
	sc = s;
	while (i < n)
	{
		if (sc[i] == (unsigned char)c)
		{
			return ((void *)sc + i);
		}
		i++;
	}
	return (NULL);
}
