/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_brack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:03 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:03 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"

int	ft_match_brack(t_regmatch *rm, int pos, t_regex *cur)
{
	t_opbrack	*bk;

	bk = (t_opbrack*)cur;
	if (bk->str[0] != '^' && ft_isinarray(rm->str[pos], bk->str))
		return (1);
	else if (!ft_isinarray(rm->str[pos], bk->str + 1))
		return (1);
	return (0);
}
