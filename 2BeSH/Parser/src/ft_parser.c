#include "ft_parser_private.h"
#include "ft_stocker.h"
#include "ft_resolver.h"


#include "ft_lexer.h"
#include "common.h"
#include <stdio.h>

#include <stdlib.h>

static void	parser_start(t_lex *begin)
{
	t_pars		*test;

	test = parser_singleton()->parse(begin);

	printf("op test = : %d\n", test->op->op);
	if (test->right)
		printf("op test right = : %d\n", test->right->op->op);
	else
		printf("op test right = : NULL\n");
	if (test->left)
		printf("op test left  = : %d\n", test->left->op->op);
	else
		printf("op test left = : NULL \n");
	/*	ops = parser_singleton()->parse(stocker_singleton()->to_string());
	resolver_singleton()->start(ops);
	stocker_singleton()->clean(); */
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
