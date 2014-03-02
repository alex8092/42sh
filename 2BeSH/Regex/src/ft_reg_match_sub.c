/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reg_match_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 19:30:18 by amerle            #+#    #+#             */
/*   Updated: 2014/03/01 23:24:46 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include <stdlib.h>

t_bool	ft_match_sub(t_op_sub *sub, t_reg *reg)
{
	size_t	s_pos;
	t_regop	*tmp;

	s_pos = reg->pos;
	tmp = (t_regop *)ft_memalloc(sizeof(t_regop));
	tmp->next = sub->begin_op;
	if (ft_reg_match_ismatchnext(tmp, reg, -1))
	{
		free(tmp);
		return (true);
	}
	free(tmp);
	reg->pos = s_pos;
	return (false);
}

void	ft_reg_parse_sub(t_reg *reg)
{
	t_regop	*prev;

	prev = reg->save_op;
	reg->save_op = ft_reg_create_op(REGOP_SUB, reg);
	((t_op_sub *)reg->save_op)->prev_sop = prev;
	++reg->pos_reg;
}

void	ft_reg_parse_sub_end(t_reg *reg)
{
	((t_op_sub *)reg->save_op)->begin_op = reg->save_op->next;
	reg->save_op->next = 0;
	reg->end_op = reg->save_op;
	reg->save_op = ((t_op_sub *)reg->save_op)->prev_sop;
	++reg->pos_reg;
}
