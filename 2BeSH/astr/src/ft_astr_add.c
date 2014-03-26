/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astr_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:36:41 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:45:35 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astr_private.h"
#include <stdlib.h>

t_bool	p_astr_add(t_astr *astr, char *str)
{
	char	**new;
	size_t	i;

	if (astr)
	{
		i = 0;
		new = (char **)malloc(sizeof(char *) * (astr->m_size + 1));
		while (i < astr->m_size)
		{
			new[i] = astr->m_arr[i];
			++i;
		}
		new[i] = str;
		++astr->m_size;
		if (astr->m_arr)
			free(astr->m_arr);
		astr->m_arr = new;
		return (true);
	}
	return (false);
}
