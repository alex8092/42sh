/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astr_erase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:36:51 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:45:48 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astr_private.h"

static t_bool	zero(size_t *i, size_t *i2)
{
	*i = 0;
	*i2 = 0;
	return (true);
}

char			*p_astr_erase(t_astr *astr, size_t index)
{
	char	**new;
	char	*str;
	size_t	j;
	size_t	k;

	if (astr && index < astr->m_size && zero(&j, &k))
	{
		new = (char **)malloc(sizeof(char *) * (astr->m_size - 1));
		while (j < astr->m_size)
		{
			if (j != index)
			{
				new[k] = astr->m_arr[j];
				++k;
			}
			else
				str = astr->m_arr[j];
			++j;
		}
		free(astr->m_arr);
		astr->m_arr = new;
		--astr->m_size;
		return (str);
	}
	return (NULL);
}
