/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:39:07 by amerle            #+#    #+#             */
/*   Updated: 2014/03/26 10:34:24 by rivers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <unistd.h>

void	ft_putstr_fd(int fd, char const *str)
{
	ssize_t	ret;

	if (fd == 2)
		write(2, "\033[1;31m", 7);
	ret = write(fd, str, ft_strlen(str));
	if (fd == 2)
		write(2, "\033[0m", 4);
	(void)ret;
}
