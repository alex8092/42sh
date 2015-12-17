/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:59 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:48:16 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_putchar_fd(int fd, char c)
{
	ssize_t	ret;

	ret = write(fd, &c, 1);
	(void)ret;
}