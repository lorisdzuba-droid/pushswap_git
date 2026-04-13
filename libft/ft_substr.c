/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:31:39 by ldzuba            #+#    #+#             */
/*   Updated: 2025/10/31 14:32:00 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	count = ft_strlen(s);
	if (count <= start)
		return (ft_strdup(""));
	if ((count - start) < len)
		len = count - start;
	sub = (char *)malloc ((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// int	main(void)
// {
// 	printf("ft %s\n", ft_substr("a", 0, 1000));
// 	return (0);
// }