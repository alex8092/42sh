/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_any.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:02 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:02 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"

int	ft_match_any(t_regmatch *rm, int pos, t_regex *cur)
{
	(void)rm;
	(void)pos;
	(void)cur;
	if (rm->str[pos])
		return (1);
	return (0);
}
