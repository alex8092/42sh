#include "ft_parser_private.h"
#include "ft_stocker.h"
#include "ft_resolver.h"


#include "ft_lexer.h"
#include "common.h"
#include <stdio.h>

#include <stdlib.h>

static void	parser_start(t_lex *begin)
{
	parser_singleton()->parse(begin);
	return ;
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
		if (!singleton)
			exit(1);
		parser_init(singleton);
	}
	return (singleton);
}
