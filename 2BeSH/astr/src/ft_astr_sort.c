/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astr_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:37:08 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:46:08 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astr_private.h"

static void	astrsort_rec(t_astr *astr, size_t l, t_bool (*f)(char *, char *))
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = 0;
	if (l > 1)
	{
		while (i < l)
		{
			s1 = astr->get(astr, i);
			s2 = astr->get(astr, i + 1);
			if (!s1 || !s2 || f(s1, s2))
			{
				astr->set(astr, i, s2);
				astr->set(astr, i + 1, s1);
			}
			++i;
		}
	}
	else
		return ;
	astrsort_rec(astr, l - 1, f);
}

t_astr		*p_astr_sort(t_astr *astr, t_bool (*f)(char *, char *))
{
	if (astr && f)
		astrsort_rec(astr, astr->m_size - 1, f);
	return (astr);
}
