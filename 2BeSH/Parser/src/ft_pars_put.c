#include "ft_parser_private.h"

static t_pars	*put_children(t_pars *lst , t_lex *op, p_child child)
{
	t_lex		*tmp;

	tmp = op;
	if (child == RIGHT)
	{
		lst->right = p_pars_init();
		lst->right->parent = lst;
		lst->right->op = tmp;
	}
	else
	{
		lst->left = p_pars_init();
		lst->left->parent = lst;
		lst->left->op = tmp;
	}
	return (lst);
}

t_pars			*p_put_op(t_pars *lst, t_lex *begin)
{
	t_lex	*tmp;
	t_lex	*op;

	if (!lst)
		lst = p_pars_init();
	op = p_find_op(begin);
	if ((op->op / 10) > 0)
	{
		tmp = op->next;
		op->next = NULL;
		lst->op = op;
		if (tmp != NULL)
			lst = put_children(lst , tmp, RIGHT);
		tmp = begin;
		while (tmp->next != op && tmp != op)
			tmp = tmp->next;
		tmp->next = NULL;
		if (tmp != op)
			lst = put_children(lst, begin , LEFT);
	}
	return (lst);
}
