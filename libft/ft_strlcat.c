/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:41:45 by ldzuba            #+#    #+#             */
/*   Updated: 2025/10/31 17:14:54 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	j;

	j = 0;
	if (!dst || !src)
		return (0);
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	while (src[j] && (len_dst + j + 1) < size)
	{
		dst[len_dst + j] = src[j];
		j++;
	}
	dst[len_dst + j] = 0;
	if (len_dst > size)
		return (size + len_src);
	return (len_dst + len_src);
}

// #include <bsd/string.h>

// int	main(void)
// {
// 	char	*dst = "";
// 	char	*dst2 = "";
// 	size_t	d;

// 	d = 10;
// 	printf("ft %zu\n %s\n", ft_strlcat(dst, "sit amet", d), dst);
// 	printf("or %zu\n %s\n", strlcat(dst2, "sit amet", d), dst2);
// 	return (0);
// }