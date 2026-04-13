/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:02:54 by ldzuba            #+#    #+#             */
/*   Updated: 2025/10/30 13:38:35 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*strf;

	if (!s || !f)
		return (NULL);
	i = 0;
	strf = (char *)malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!strf)
		return (NULL);
	while (s[i])
	{
		strf[i] = f(i, s[i]);
		i++;
	}
	strf[i] = '\0';
	return (strf);
}
