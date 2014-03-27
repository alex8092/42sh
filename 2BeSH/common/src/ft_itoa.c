/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:36:54 by triviere          #+#    #+#             */
/*   Updated: 2014/03/27 21:36:56 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

size_t		count_n(unsigned int number)
{
	if (number)
		return (1 + count_n(number / 10));
	return (1);
}

static char	*itoa_re(char *str, unsigned int number, size_t count)
{
	char	c;

	if (count)
	{
		c = number % 10 + '0';
		itoa_re(str, number / 10, count - 1);
		str[count - 1] = c;
		return (str);
	}
	return (str - 1);
}

char		*ft_itoa(int number)
{
	char			*str;
	size_t			count;
	unsigned int	n;

	n = (number < 0) ? -number : number;
	if (n != 0)
		count = count_n(n) - 1;
	else
		return (ft_strdup("0"));
	if (number < 0)
		++count;
	str = (char *)ft_memalloc(count + 1);
	if (number < 0)
	{
		*str = '-';
		itoa_re(str + 1, n, count - 1);
	}
	else
		itoa_re(str, n, count);
	return (str);
}
