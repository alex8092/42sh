/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astr_joinall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:37:01 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:45:59 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astr_private.h"

static size_t	p_count_total(t_astr *astr, int *lens)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < astr->m_size)
	{
		lens[i] = ft_strlen(astr->m_arr[i]);
		count += lens[i];
		++i;
	}
	return (count);
}

char			*p_astr_joinall(t_astr *astr)
{
	char	*new;
	size_t	i;
	size_t	count;
	int		*lens;

	new = NULL;
	if (astr)
	{
		lens = (int *)malloc(sizeof(int) * (astr->m_size));
		count = p_count_total(astr, lens);
		new = (char *)malloc(sizeof(char) * (count + 1));
		if (new && !(i = 0))
		{
			count = 0;
			while (i < astr->m_size)
			{
				ft_strncpy(new + count, astr->m_arr[i], lens[i]);
				count += lens[i];
				++i;
			}
			new[count] = 0;
		}
		free(lens);
	}
	return (new);
}
