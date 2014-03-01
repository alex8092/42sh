/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:07:25 by amerle            #+#    #+#             */
/*   Updated: 2014/03/01 23:16:13 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)s;
	if (tmp)
	{
		i = 0;
		while (tmp[i] && tmp[i] != (char)c)
			++i;
		if (tmp[i] == (char)c)
			return (tmp + i);
	}
	return (0);
}
