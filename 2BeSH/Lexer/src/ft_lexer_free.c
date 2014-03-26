/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:59 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:42:59 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer_private.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_lex_free_item(t_lex *item)
{
	if (item)
	{
		ft_strdel(&item->str);
		free(item);
	}
}

void	ft_lex_free(t_lex *lex)
{
	p_lexer_free(lex);
}

void	p_lexer_free(t_lex *begin)
{
	t_lex	*tmp;

	tmp = begin;
	while (tmp)
	{
		begin = tmp->next;
		ft_strdel(&tmp->str);
		free(tmp);
		tmp = begin;
	}
}
