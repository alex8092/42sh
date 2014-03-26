/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:04 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:04 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"

char	*ft_regmatch(char *str, t_regex *regex, size_t *len_match)
{
	t_regmatch	rm;
	int			size;

	rm.str = str;
	rm.pos = 0;
	rm.begin = regex;
	if ((size = ft_matcher(&rm, rm.pos, rm.begin)))
	{
		*len_match = size;
		return (str + rm.pos);
	}
	return (NULL);
}
