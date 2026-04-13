/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:24:06 by ldzuba            #+#    #+#             */
/*   Updated: 2025/12/17 16:26:24 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clear(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
		free(ret[i++]);
	free(ret);
}

static void	*ft_words_start(char const *s, char c, char **ret, int *j)
{
	int	i;
	int	z;

	i = 0;
	*j = 0;
	while (*(s + i) && *(s + i) == c)
		i++;
	while (*(s + i))
	{
		z = 0;
		while (*(s + i + z) && *(s + i + z) != c)
			z++;
		ret[*j] = ft_substr(s, i, z);
		if (ret[(*j)++] == NULL)
		{
			ft_clear(ret);
			return (NULL);
		}
		i += z;
		if (*(s + i))
			while (*(s + i) && *(s + i) == c)
				i++;
	}
	return (ret);
}

static void	*ft_words(char const *s, char c, int n)
{
	char	**ret;
	int		j;

	ret = malloc(sizeof(char *) * (n + 1));
	if (ret == NULL)
		return (NULL);
	if (ft_words_start(s, c, ret, &j) == NULL)
		return (NULL);
	ret[j] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		n;

	if (!s)
		return (NULL);
	i = 0;
	n = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			while (*(s + i) && *(s + i) != c)
				i++;
			n++;
		}
		if (*(s + i) == c)
			while (*(s + i) && *(s + i) == c)
				i++;
	}
	return (ft_words(s, c, n));
}
