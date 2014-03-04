/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reg_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 09:55:24 by amerle            #+#    #+#             */
/*   Updated: 2014/03/03 17:23:56 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"

static t_regop	*ft_get_op(char type)
{
	if (type == REGOP_BASE)
		return ((t_regop *)ft_memalloc(sizeof(t_op_base)));
	else if (type == REGOP_BRACK)
		return ((t_regop *)ft_memalloc(sizeof(t_op_brack)));
	else if (type == REGOP_REP)
		return ((t_regop *)ft_memalloc(sizeof(t_op_rep)));
	else if (type == REGOP_ANY)
		return ((t_regop *)ft_memalloc(sizeof(t_op_any)));
	else if (type == REGOP_STAR)
		return ((t_regop *)ft_memalloc(sizeof(t_op_star)));
	else if (type == REGOP_BEGEND)
		return ((t_regop *)ft_memalloc(sizeof(t_op_begend)));
	else if (type == REGOP_SUB)
		return ((t_regop *)ft_memalloc(sizeof(t_op_sub)));
	else
		return (0);
}

static void	ft_reg_config_op(char type, t_regop *op, t_reg *reg)
{
	if (type == REGOP_REP)
		((t_op_rep *)op)->rep = reg->end_op;
	else if (type == REGOP_STAR)
	{
		((t_op_star *)op)->rep = (t_op_rep *)ft_get_op(REGOP_REP);
		((t_op_star *)op)->rep->rep = reg->end_op;
		reg->end_op->skip_false = true;
	}
	reg->end_op->next = op;
	if (reg->end_op->type == REGOP_STAR)
		((t_op_star *)reg->end_op)->rep->base.next = op;
	reg->end_op = op;
}

t_regop	*ft_reg_create_op(char type, t_reg *reg)
{
	t_regop	*op;

	op = ft_get_op(type);
	op->type = type;
	if (reg->beg_op == 0)
	{
		reg->beg_op = op;
		reg->end_op = op;
	}
	else
		ft_reg_config_op(type, op, reg);
	return (op);
}
