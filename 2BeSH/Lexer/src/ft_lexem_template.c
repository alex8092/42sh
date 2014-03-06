#include "ft_lexer_private.h"
#include "ft_security.h"

static t_lex_reg	*ft_new_lti(t_lex_reg *p, char *pattern, t_lex_op op)
{
	t_lex_reg	*t;

	t = (t_lex_reg*)ft_memalloc(sizeof(t_lex_reg));
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
	t = ft_new_lti(t, "[123]?>>", LEX_OP_APPEND_OUT);
	t = ft_new_lti(t, "[123]?>", LEX_OP_REDIRECT_OUT);
	t = ft_new_lti(t, "<", LEX_OP_REDIRECT_IN);
	t = ft_new_lti(t, "\"([^\\][^\"]?){0,}[^\\]\"", LEX_OP_STR);
	t = ft_new_lti(t, "\"[^\\]\"", LEX_OP_STR);
	t = ft_new_lti(t, "'.{0,}[^\\]'", LEX_OP_STR);
	t = ft_new_lti(t, "'[^\\]\'", LEX_OP_STR);
	t = ft_new_lti(t, "`.{0,}[^\\]`", LEX_OP_SUBCOMMAND);
	t = ft_new_lti(t, "`[^\\]`", LEX_OP_SUBCOMMAND);
	t = ft_new_lti(t, "&&", LEX_OP_AND);
	t = ft_new_lti(t, "&", LEX_OP_BACK);
	t = ft_new_lti(t, "||", LEX_OP_OR);
	t = ft_new_lti(t, "|", LEX_OP_PIPE);
	t = ft_new_lti(t, "\\*", LEX_STAR);
	t = ft_new_lti(t, "[^ \t\"'`]{1,}", LEX_OP_WORD);
}
