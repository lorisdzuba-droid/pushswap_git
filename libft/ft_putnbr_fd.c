/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldzuba <ldzuba@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:40:19 by ldzuba            #+#    #+#             */
/*   Updated: 2025/10/28 17:04:34 by ldzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putint(long int n, int fd)
{
	if (n > 9)
	{
		ft_putint(n / 10, fd);
		ft_putchar((n % 10) + '0', fd);
	}
	else
		ft_putchar(n + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	lnb;

	lnb = n;
	if (lnb < 0)
	{
		write (fd, "-", 1);
		ft_putint(-lnb, fd);
	}
	else
		ft_putint(lnb, fd);
}
