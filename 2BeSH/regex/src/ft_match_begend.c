/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_begend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:03 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:03 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"

int	ft_match_beg(t_regmatch *rm, int pos, t_regex *cur)
{
	(void)rm;
	(void)cur;
	if (pos == 0)
		return (1);
	return (0);
}

int	ft_match_end(t_regmatch *rm, int pos, t_regex *cur)
{
	(void)rm;
	(void)pos;
	(void)cur;
	if (rm->str[pos] == 0)
		return (1);
	return (0);
}
