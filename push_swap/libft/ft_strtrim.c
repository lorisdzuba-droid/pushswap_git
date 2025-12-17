/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:19 by ldzuba            #+#    #+#             */
/*   Updated: 2025/10/28 12:08:38 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		debut;
	int		fin;
	char	*trimed;

	if (!s1 || !set)
		return (NULL);
	debut = 0;
	while (s1[debut] && ft_strchr(set, s1[debut]))
		debut++;
	fin = ft_strlen(s1) - 1;
	while (fin >= debut && ft_strrchr(set, s1[fin]))
		fin--;
	trimed = (char *)malloc ((fin - debut + 2) * sizeof(char));
	if (!trimed)
		return (NULL);
	ft_strlcpy(trimed, s1 + debut, fin - debut + 2);
	return (trimed);
}
