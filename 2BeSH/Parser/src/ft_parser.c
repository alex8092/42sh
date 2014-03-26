/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:00 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 09:35:32 by rivers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser_private.h"
#include "ft_resolver.h"
#include "ft_lexer.h"
#include <stdlib.h>

static void	parser_free(t_pars *tree)
{
	if (tree)
	{
		parser_free(tree->left);
		parser_free(tree->right);
		if (tree->op)
			ft_lex_free(tree->op);
		free(tree);
	}
}

static void	parser_start(t_lex *begin)
{
	t_pars	*tree;

	if (begin)
	{
		tree = parser_singleton()->parse(begin);
		resolver_singleton()->start(tree);
		parser_free(tree);
	}
}

static void	parser_init(t_parser *p)
{
	p->start = parser_start;
	p->parse = p_parser_parse;
}

t_parser	*parser_singleton(void)
{
	static t_parser	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_parser*)malloc(sizeof(t_parser));
		parser_init(singleton);
	}
	return (singleton);
}
