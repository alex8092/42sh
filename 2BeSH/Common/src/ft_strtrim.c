/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:41:28 by amerle            #+#    #+#             */
/*   Updated: 2014/03/01 23:27:23 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

static size_t	ft_strtrim_count_begin(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] && ft_isinarray(s[i], " \t\n\r\v\f"))
		++i;
	return (i);
}

static size_t	ft_strtrim_count_end(char const *s, size_t len)
{
	size_t	count;
	int		i;

	count = 0;
	i = len - 1;
	while (i >= 0 && ft_isinarray(s[i], " \t\n\r\v\f"))
	{
		++count;
		--i;
	}
	return (count);
}

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	size_t	off_begin;

	if (s)
	{
		len = ft_strlen(s);
		len -= ft_strtrim_count_end(s, len);
		off_begin = ft_strtrim_count_begin(s);
		len -= off_begin;
		if (len < 0)
			return (ft_strdup(""));
		str = (char *)malloc(sizeof(char) * (len + 1));
		ft_strncpy(str, s + off_begin, len);
		if (str)
			str[len] = 0;
		return (str);
	}
	return (0);
}
