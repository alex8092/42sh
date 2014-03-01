/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regmatch_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 20:50:17 by amerle            #+#    #+#             */
/*   Updated: 2014/03/01 23:19:03 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"

char	*ft_regmatch_sub(char *str, char *pattern)
{
	char	*match;
	size_t	len;

	if (str && pattern)
	{
		match = ft_regmatch(str, pattern, &len);
		if (match)
		{
			match = ft_strsub(match, 0, len);
			return (match);
		}
	}
	return (NULL);
}
