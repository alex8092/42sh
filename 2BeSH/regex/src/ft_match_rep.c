/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_rep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:03 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 07:00:04 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"

static t_bool	ca(const t_oprep *rep, int recur)
{
	return (rep->max != 0 && recur == rep->max);
}

static t_bool	cb(t_regmatch *rm, int *size, int postmp, t_regex *next)
{
	return (((*size) = ft_match(rm, postmp, next)));
}

static t_bool	cc(const t_oprep *rep, t_regex *next)
{
	return (rep->min == 0 && next);
}

static void		init(int *size, int *recur, t_regex **cur, t_regex **next)
{
	*size = 0;
	*recur = -1;
	*cur = (*cur)->next;
	*next = (*cur)->next;
}

int				ft_match_rep(t_regmatch *rm, int pos, t_regex *cur, int postmp)
{
	int				size;
	int				recur;
	const t_oprep	*rep = (t_oprep *)cur;
	t_regex			*next;

	init(&size, &recur, &cur, &next);
	if (cur->type == REGOP_SUB && ((t_opsub*)cur)->type_sub == 0)
	{
		while (next->type != REGOP_SUB && ((t_opsub*)next)->type_sub == 1)
			next = next->next;
		next = next->next;
	}
	while (rm->str[postmp])
	{
		if (ca(rep, recur) || (cc(rep, next) && cb(rm, &size, postmp, next))
			|| !(size = ft_match_dispatch(rm, postmp, cur)))
			break ;
		postmp += size;
		if (next && (size = ft_match(rm, postmp, next)))
			break ;
		++recur;
	}
	return (postmp - pos);
}
