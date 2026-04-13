/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:55:55 by ldzuba            #+#    #+#             */
/*   Updated: 2025/10/31 14:33:21 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*joint;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joint = (char *)malloc ((len1 + len2 + 1) * sizeof(char));
	if (!joint)
		return (NULL);
	ft_strlcpy(joint, s1, len1 + 1);
	ft_strlcat(joint, s2, len1 + len2 + 1);
	return (joint);
}
