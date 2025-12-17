/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:31:42 by ldzuba            #+#    #+#             */
/*   Updated: 2025/10/28 14:57:05 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_int(long int n, int sign)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		size++;
		n = n / 10;
	}
	return (size + sign);
}

static char	*ft_int_to_str(long int long_n, int sign, char *strn, int size)
{
	if (size > sign)
	{
		ft_int_to_str(long_n / 10, sign, strn, size - 1);
		strn[--size] = (long_n % 10) + '0';
	}
	if (sign > 0)
		strn[0] = '-';
	return (strn);
}

char	*ft_itoa(int n)
{
	long int	long_n;
	int			sign;
	char		*strn;
	int			size;

	long_n = n;
	sign = (long_n < 0);
	if (sign > 0)
		long_n = -long_n;
	size = ft_size_int(long_n, sign);
	strn = (char *)malloc ((size + 1) * sizeof(char));
	if (!strn)
		return (NULL);
	strn[size] = '\0';
	strn = ft_int_to_str(long_n, sign, strn, size);
	return (strn);
}
