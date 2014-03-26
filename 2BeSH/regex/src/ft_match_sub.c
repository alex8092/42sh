/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:03 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:03 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"

int	ft_match_sub(t_regmatch *rm, int pos, t_regex *cur)
{
	int	size;

	if (cur->next && (size = ft_match(rm, pos, cur->next)))
		return (size);
	(void)size;
	(void)rm;
	(void)pos;
	(void)cur;
	return (1);
}
