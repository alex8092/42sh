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

t_lex			*ft_lexer_get_lex(t_lex *parent, char **str)
{
	static t_lex_reg	*begin = NULL;
	t_lex_reg			*cur;
	size_t				len;
	char				*res;

	if (!begin)
		begin = lexer_singleton()->m_reg_begin;
	cur = begin;
	debug(1, "\n\t[COMPARE]");
	while (cur)
	{
		printf("compare match : { \"%s\" } <=> pattern { \"%s\" }\n", *str, cur->pattern);
/*		debug(5, "compare match : { \\\"", *str, "\\\" } <=> pattern { \\\"", cur->pattern, "\\\" }\n");*/
		if ((res = ft_regmatch(*str, cur->pattern, &len)) == *str)
		{
			printf("\tlen : %ld\n", len);
			debug(1, "\t[MATCH]\n");
			*str += len;
			return (ft_create_lex(parent, ft_strsub((*str) - len, 0, len), cur->op));
		}
		cur = cur->next;
	}
	++(*str);
	debug(1, "\t[NOMATCH]\n");
	return (ft_create_lex(parent, ft_strsub((*str) - 1, 0, 1), LEX_UNKNOW));
}

void			ft_lexer_lex_str(char *str)
{
	t_lex		*begin;
	t_lex		*end;
	size_t		index;
	char		*tmp;

	begin = NULL;
	end = NULL;
	debug(1, "$> start lexer");
	index = 0;
	tmp = str;
	while (*tmp)
	{
		if (*tmp != ' ' && *tmp != '\t')
		{
			end = ft_lexer_get_lex(end, &tmp);
			if (!begin)
				begin = end;
		}
		else
			++tmp;
	}
	lexer_singleton()->m_event_complete(begin);
}

