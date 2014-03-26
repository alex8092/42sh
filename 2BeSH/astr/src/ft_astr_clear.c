/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astr_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:36:45 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:45:39 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astr_private.h"

void	p_astr_clear(t_astr *astr, t_bool del)
{
	size_t	i;

	if (astr)
	{
		i = 0;
		if (del)
		{
			while (i < astr->m_size)
			{
				free(astr->m_arr[i]);
				++i;
			}
		}
		free(astr->m_arr);
		astr->m_arr = 0;
		astr->m_size = 0;
	}
}
