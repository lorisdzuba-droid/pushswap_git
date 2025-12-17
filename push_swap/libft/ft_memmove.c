/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:09:13 by ldzuba            #+#    #+#             */
/*   Updated: 2025/10/31 16:39:32 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	destination = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (destination > source && destination < source + n)
	{
		while (n != 0)
		{
			n--;
			destination[n] = source [n];
		}
		return (dest);
	}
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
