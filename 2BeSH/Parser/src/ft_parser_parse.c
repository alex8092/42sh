#include "ft_parser_private.h"
#include "common.h"
#include <unistd.h>
#include <stdlib.h>
#include <ft_stocker.h>

#include <stdio.h>

static t_pars		*p_put_child(t_pars *cur)
{
	if (cur->left)
	{
		cur->left = p_put_op(cur->left, cur->left->op);
		cur->left = p_put_child(cur->left);
	}
	if (cur->right)
	{
		cur->right = p_put_op(cur->right, cur->right->op);
		cur->right = p_put_child(cur->right);
	}
	return(cur);
}

static void			puttree(t_pars *tree)
{
	t_lex	*cur;

	if (tree->op)
	{
		cur = tree->op;
		while (cur)
		{
			printf("%s ", cur->str);
			cur = cur->next;
		}
		printf("\n");
	}
	if (tree->left)
	{
		puttree(tree->left);
	}
	if (tree->right)
	{
		puttree(tree->right);
	}
}

t_pars			*p_parser_parse(t_lex *lst)
{
	t_pars		*parseur;

	parseur = NULL;
	parseur = p_put_op(parseur , lst);
	parseur = p_put_child(parseur);
	puttree(parseur);
	return (parseur);
}
