/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_lex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:59 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 07:37:37 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer_private.h"
#include <stdlib.h>
#include <stdio.h>

static t_lex	*ft_create_lex(t_lex *parent, char *str, t_lex_op op)
{
	t_lex	*item;

	item = (t_lex *)ft_memalloc(sizeof(t_lex));
	item->str = str;
	item->op = op;
	if (parent)
		parent->next = item;
	return (item);
}

static void		ft_manage_word(char *str, size_t *len)
{
	size_t	i;

	i = 0;
	while (i < *len)
	{
		if (ft_isinarray(str[i], "&;|><") && i > 0 && str[i - 1] != '\\')
			break ;
		++i;
	}
	*len = i;
}

static t_lex	*gogogo(t_lex **par, t_lex_reg *cur, char **str, size_t *len)
{
	if (cur->op == LEX_OP_WORD)
		ft_manage_word(*str, len);
	if (*par && (*par)->op == LEX_OP_BACK && cur->op >= 100)
	{
		if (cur->op != LEX_OP_SEPARATOR)
		{
			ft_putstr_fd(2, "Syntax error : No conditional after &\n");
			return (NULL);
		}
	}
	else if (*par && (*par)->op == LEX_OP_BACK)
		*par = ft_create_lex(*par, ft_strdup(";"), LEX_OP_SEPARATOR);
	return ((t_lex *)1);
}

t_lex			*ft_lexer_get_lex(t_lex *par, char **str)
{
	static t_lex_reg	*begin = NULL;
	t_lex_reg			*cur;
	size_t				l;
	char				*res;

	begin = (!begin) ? lexer_singleton()->m_reg_begin : begin;
	cur = begin;
	while (cur)
	{
		if ((res = ft_regmatch(*str, cur->pattern, &l)) == *str)
		{
			if (!gogogo(&par, cur, str, &l))
				return (NULL);
			if (l != 0 && (*str += (cur->op != 2) ? l : l + 1))
			{
				if (cur->op == LEX_OP_STR)
					return (ft_create_lex(par, ft_strsub((*str) - l,
					0, l - 2), cur->op));
				return (NEW_LEX(par, ft_strsub((*str) - l, 0, l), cur->op));
			}
		}
		cur = cur->next;
	}
	++(*str);
	return (ft_create_lex(par, ft_strsub((*str) - 1, 0, 1), LEX_UNKNOW));
}

t_lex			*ft_lexer_lex_str(char *str)
{
	t_lex		*begin;
	t_lex		*end;
	char		*tmp;

	begin = NULL;
	end = NULL;
	tmp = str;
	while (*tmp)
	{
		if (*tmp != ' ' && *tmp != '\t')
		{
			if (!(end = ft_lexer_get_lex(end, &tmp)))
				return (NULL);
			if (!begin)
				begin = end;
		}
		else
			++tmp;
	}
	return (begin);
}
