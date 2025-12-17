/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:47:57 by ldzuba            #+#    #+#             */
/*   Updated: 2025/10/31 12:59:27 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compare_all(const char *b, const char *li, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (b[i + j] == li[j] && li[j] && i < len)
	{
		j++;
	}
	if (li[j] == '\0')
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	i = 0;
	len_little = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && (i + len_little) <= len)
	{
		if (big[i] == little[0])
			if (ft_compare_all(big, little, i, len))
				return ((char *)big + i);
		i++;
	}
	return (NULL);
}

// #include <bsd/string.h>

// int	main(void)
// {
// 	const char	big[40] = "aaabcabcd";
// 	const char	little[10] = "cd";

// 	printf("ft %s\n", ft_strnstr(big, little, 8));
// 	printf("ft %s\n", strnstr(big, little, 8));
// 	return (0);
// }
