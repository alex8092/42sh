/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexem_template.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:59 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 07:08:38 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer_private.h"
#include "ft_security.h"

static t_lex_reg	*ft_new_lti(t_lex_reg *p, t_regex *pattern, t_lex_op op)
{
	t_lex_reg	*t;

	t = (t_lex_reg*)ft_memalloc(sizeof(t_lex_reg));
	t->pattern = pattern;
	t->op = op;
	if (p)
		p->next = t;
	return (t);
}

void				p_lexer_template_init(t_lexer *lexer)
{
	t_lex_reg	*t;

	t = ft_new_lti(NULL, ft_regex(";"), LEX_OP_SEPARATOR);
	lexer->m_reg_begin = t;
	t = ft_new_lti(t, ft_regex("while.{1,};[ \t]{1,}done"), LEX_OP_WHILE);
	t = ft_new_lti(t, ft_regex(">>&"), LEX_OP_APPEND_OUT);
	t = ft_new_lti(t, ft_regex("[12]{0,1}>>"), LEX_OP_APPEND_OUT);
	t = ft_new_lti(t, ft_regex(">&"), LEX_OP_REDIRECT_OUT);
	t = ft_new_lti(t, ft_regex("[12]{0,1}>"), LEX_OP_REDIRECT_OUT);
	t = ft_new_lti(t, ft_regex("<"), LEX_OP_REDIRECT_IN);
	t = ft_new_lti(t, ft_regex("\".{0,}[^\\\"]\""), LEX_OP_STR);
	t = ft_new_lti(t, ft_regex("'.{0,}[^\\']'"), LEX_OP_STR);
	t = ft_new_lti(t, ft_regex("`.{0,}[^\\`]`"), LEX_OP_SUBCOMMAND);
	t = ft_new_lti(t, ft_regex("&&"), LEX_OP_AND);
	t = ft_new_lti(t, ft_regex("&"), LEX_OP_BACK);
	t = ft_new_lti(t, ft_regex("\\|\\|"), LEX_OP_OR);
	t = ft_new_lti(t, ft_regex("\\| {0,}&"), LEX_OP_PIPE_REDIR);
	t = ft_new_lti(t, ft_regex("\\|"), LEX_OP_PIPE);
	t = ft_new_lti(t, ft_regex("[^ \t\"'`]{1,}"), LEX_OP_WORD);
}
