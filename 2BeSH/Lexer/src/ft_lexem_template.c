#include "ft_lexer_private.h"

static t_lex_reg	*ft_new_lti(t_lex_reg *p, char *pattern, t_lex_op op)
{
	t_lex_reg	*t;

	t = (t_lex_reg*)ft_memalloc(sizeof(t_lex_reg));
	if (!t)
		_exit(1);
	t->pattern = pattern;
	t->op = op;
	if (p)
		p->next = t;
	return (t);
}

void			p_lexer_template_init(t_lexer *lexer)
{
	t_lex_reg	*t;

	t = ft_new_lti(NULL, ";", LEX_OP_SEPARATOR);
	lexer->m_reg_begin = t;
	t = ft_new_lti(t, "[\\/.a-zA-Z0-9-]{1,}", LEX_OP_WORD);
	t = ft_new_lti(t, "&&", LEX_OP_AND);
	t = ft_new_lti(t, "&", LEX_OP_BACK);
	t = ft_new_lti(t, "||", LEX_OP_OR);
	t = ft_new_lti(t, "|", LEX_OP_PIPE);
}
