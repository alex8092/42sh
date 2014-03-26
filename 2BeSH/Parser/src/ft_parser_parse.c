/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:00 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:00 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser_private.h"
#include <unistd.h>
#include <stdlib.h>

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
	return (cur);
}

t_pars				*p_parser_parse(t_lex *lst)
{
	t_pars		*parseur;

	parseur = NULL;
	parseur = p_put_op(parseur, lst);
	parseur = p_put_child(parseur);
	return (parseur);
}
