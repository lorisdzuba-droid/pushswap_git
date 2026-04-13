/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:56:00 by ldzuba            #+#    #+#             */
/*   Updated: 2025/10/30 17:48:47 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		count;

	count = 0;
	while (s[count])
		count++;
	ptr = malloc((count + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (count >= 0)
	{
		ptr[count] = s[count];
		count--;
	}
	return (ptr);
}
