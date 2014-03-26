/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:39:03 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 06:43:24 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	ft_putnbr_fd_rec(int fd, unsigned long nbr)
{
	char	c;

	if (nbr)
	{
		c = (nbr % 10) + '0';
		ft_putnbr_fd_rec(fd, nbr /= 10);
		ft_putchar_fd(fd, c);
	}
}

void		ft_putnbr_fd(int fd, long nbr)
{
	if (nbr < 0)
	{
		ft_putchar_fd(fd, '-');
		ft_putnbr_fd_rec(fd, -nbr);
	}
	else
		ft_putnbr_fd_rec(fd, nbr);
}
