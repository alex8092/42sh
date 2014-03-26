/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:04 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:04 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_resolver.h"
#include <ft/regex.h>

void	ft_resolv_format(t_operation *op)
{
	static t_regex	*reg = NULL;
	t_lex			*cur;

	if (!reg)
		reg = ft_regex("\\");
	cur = op->lex;
	while (cur)
	{
		cur->str = ft_regmatch_replace_all(cur->str, reg, "");
		cur = cur->next;
	}
}
