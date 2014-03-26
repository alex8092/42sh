/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:48 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:48:02 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	end_star(char *s2)
{
	while (s2 && *s2 && *s2 == '*')
		s2++;
	if (*s2 == '\0')
		return (1);
	return (0);
}

int			ft_matchn(char *s1, char *s2)
{
	int		result;

	result = 0;
	if (s2 && *s2 == '\0' && s1 && *s1 == '\0')
		return (1);
	else if (s1 && *s1 == '\0')
		return (0);
	if (s1 && s2 && *s1 != *s2 && *s2 != '*' && *s2 != '?')
		return (0);
	else if ((s1 && s2 && *s1 == *s2) || *s2 == '?')
		return (ft_matchn(s1 + 1, s2 + 1));
	if (s2 && *s2 == '*')
	{
		result += ft_matchn(s1 + 1, s2);
		result += ft_matchn(s1 + 1, s2 + 1);
		return (result);
	}
	if (end_star(s2))
		return (1);
	return (0);
}
