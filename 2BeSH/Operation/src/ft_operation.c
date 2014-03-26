/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:00 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:00 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"
#include "ft_lexer.h"
#include <stdlib.h>

t_operation		*ft_new_operation(t_operation *parent, t_lex *lex)
{
	t_operation	*new;

	new = (t_operation*)ft_memalloc(sizeof(t_operation));
	new->lex = lex;
	new->fd_out = -1;
	new->fd_in = -1;
	new->fd_err = -1;
	if (parent)
		parent->next = new;
	return (new);
}

void			ft_free_op(t_operation *op)
{
	t_operation	*next;

	while (op)
	{
		next = op->next;
		if (op->exec_file)
			free(op->exec_file);
		free(op);
		op = next;
	}
}
