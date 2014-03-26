/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:39:52 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:48:55 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <unistd.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		lim;
	long int	*dest2;
	long int	*src2;

	i = 0;
	if (dest && src && n > 0)
	{
		lim = n / sizeof(long int);
		dest2 = (long int *)dest;
		src2 = (long int *)src;
		while (i < lim)
		{
			dest2[i] = src2[i];
			++i;
		}
		i *= sizeof(long int);
		while (i < n)
		{
			dest[i] = src[i];
			++i;
		}
	}
	return (dest);
}
