#include "ft_lexer_private.h"
#include "ft_debug.h"
#include "ft_regex.h"
#include <stdlib.h>
#include <stdio.h>

static t_lex	*ft_create_lex(t_lex *parent, char *str, t_lex_op op)
{
	t_lex	*item;

	item = (t_lex *)ft_memalloc(sizeof(t_lex));
	if (!item)
		_exit(1);
	item->str = str;
	item->op = op;
	if (parent)
		parent->next = item;
	return (item);
}

t_lex			*ft_lexer_get_lex(char **str)
{
	static t_lex_reg	*begin = NULL;
	t_lex_reg			*cur;
	size_t				len;
	char				*res;

	if (!begin)
		begin = lexer_singleton()->m_reg_begin;
	cur = begin;
	debug(1, "\n\t[COMPARE]");
	while ((*str)[0] != ' ' && cur)
	{
		debug(5, "compare match : { \\\"", *str, "\\\" } <=> pattern { \\\"", cur->pattern, "\\\" }\n");
		if ((res = ft_regmatch(*str, cur->pattern, &len)) == *str)
		{
			printf("\tlen : %ld\n", len);
			debug(1, "\t[MATCH]\n");
			*str += len;
			return (NULL);
		}
		cur = cur->next;
	}
	++(*str);
	debug(1, "\t[NOMATCH]\n");
	return (NULL);
}

void			ft_lexer_lex_str(char *str)
{
	t_lex		*begin;
	t_lex		*end;
	size_t		index;
	t_lex_reg	*beg_reg;
	char		*tmp;

	begin = NULL;
	end = NULL;
	debug(1, "$> start lexer");
	index = 0;
	beg_reg = lexer_singleton()->m_reg_begin;
	tmp = str;
	while (*tmp)
	{
		if (*tmp != ' ')
			ft_lexer_get_lex(&tmp);
		else
			++tmp;
	}
	(void)ft_create_lex;
}

