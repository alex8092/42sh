/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:00 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:00 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser_private.h"

static t_pars	*put_children(t_pars *lst, t_lex *op, t_child child)
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
	if ((op->op / 10) >= 10)
	{
		tmp = op->next;
		op->next = NULL;
		lst->op = op;
		if (tmp != NULL)
			lst = put_children(lst, tmp, RIGHT);
		tmp = begin;
		while (tmp->next != op && tmp != op)
			tmp = tmp->next;
		tmp->next = NULL;
		if (tmp != op)
			lst = put_children(lst, begin, LEFT);
	}
	else
		lst->op = op;
	return (lst);
}
