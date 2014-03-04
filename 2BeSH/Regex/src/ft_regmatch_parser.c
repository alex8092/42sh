/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regmatch_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 09:51:06 by amerle            #+#    #+#             */
/*   Updated: 2014/03/03 18:03:42 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include <stdlib.h>

static void	ft_reg_parse_brack(t_reg *reg)
{
	t_op_brack	*brack;
	char		*str;
	size_t		c;
	size_t		i;

	c = 0;
	brack = (t_op_brack *)ft_reg_create_op(REGOP_BRACK, reg);
	str = reg->s_reg + reg->pos_reg;
	i = 1;
	if (str[i] == ']')
		++i;
	while (str[i] && (str[i] != ']' || c))
	{
		if (str[i] == '[')
			++c;
		else if (str[i] == ']' && c)
			--c;
		else if (str[i] == ']')
			break ;
		++i;
	}
	brack->s_brack = ft_strsub(str, 1, i - 1);
	reg->pos_reg += i;
	++reg->pos_reg;
}

void		ft_reg_parse_base(t_reg *reg)
{
	t_op_base	*base;

	base = (t_op_base *)ft_reg_create_op(REGOP_BASE, reg);
	base->find = reg->s_reg[reg->pos_reg];
	++reg->pos_reg;
	reg->escape = false;
}

static void	ft_reg_parse_rep(t_reg *reg)
{
	t_op_rep	*rep;
	char		*str;
	char		*str2;
	size_t		tmp;

	rep = (t_op_rep *)ft_reg_create_op(REGOP_REP, reg);
	str = ft_strchr(reg->s_reg + reg->pos_reg, '}');
	if (!str)
		return ;
	tmp = str - (reg->s_reg + reg->pos_reg);
	str = ft_strsub(reg->s_reg, reg->pos_reg + 1, tmp);
	rep->min_rep = ft_atoi(str);
	if (!rep->min_rep)
		rep->rep->skip_false = true;
	str2 = ft_strchr(str, ',');
	if (str2)
		rep->max_rep = ft_atoi(str2 + 1);
	else
	{
		rep->max_rep = rep->min_rep;
		str2 = str;
	}
	str2 = ft_strchr(str2, '}');
	reg->pos_reg += str2 - str + 2;
	free(str);
}

static void	ft_reg_parse_plus(t_reg *reg)
{
	t_op_star	*star;

	star = (t_op_plus *)ft_reg_create_op(REGOP_PLUS, reg);
	star->rep->min_rep = 1;
	star->rep->max_rep = 0;
	++reg->pos_reg;
}

void		ft_reg_parse(t_reg *reg)
{
	while (reg->s_reg[reg->pos_reg])
	{
		if (reg->s_reg[reg->pos_reg] == '[' && !reg->escape)
			ft_reg_parse_brack(reg);
		else if (reg->s_reg[reg->pos_reg] == '{' && !reg->escape)
			ft_reg_parse_rep(reg);
		else if (reg->s_reg[reg->pos_reg] == '.' && !reg->escape)
			ft_reg_parse_any(reg);
		else if (reg->s_reg[reg->pos_reg] == '*' && !reg->escape)
			ft_reg_parse_star(reg);
		else if (reg->s_reg[reg->pos_reg] == '^' && !reg->escape)
			ft_reg_parse_begend(reg, true);
		else if (reg->s_reg[reg->pos_reg] == '$' && !reg->escape)
			ft_reg_parse_begend(reg, false);
		else if (reg->s_reg[reg->pos_reg] == '?' && !reg->escape)
			ft_reg_parse_quest(reg);
		else if (reg->s_reg[reg->pos_reg] == '+' && !reg->escape)
			ft_reg_parse_plus(reg);
		else if (reg->s_reg[reg->pos_reg] == '(' && !reg->escape)
			ft_reg_parse_sub(reg);
		else if (reg->s_reg[reg->pos_reg] == ')' && !reg->escape)
			ft_reg_parse_sub_end(reg);
		else if (reg->s_reg[reg->pos_reg] == '\\' && !reg->escape)
			ft_reg_parse_slash(reg);
		else
			ft_reg_parse_base(reg);
	}
}
