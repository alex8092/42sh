/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:39:59 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:49:07 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s && len > 0)
	{
		str = (char *)malloc(sizeof(char) * (len + 1));
		ft_strncpy(str, s + start, len);
		str[len] = 0;
		return (str);
	}
	return (ft_strdup(""));
}
