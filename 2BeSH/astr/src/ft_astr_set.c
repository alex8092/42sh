/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astr_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:37:05 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:46:05 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astr_private.h"

char	*p_astr_set(t_astr *astr, size_t index, char *str)
{
	char	*tmp;

	tmp = NULL;
	if (astr && index < astr->m_size)
	{
		tmp = astr->m_arr[index];
		astr->m_arr[index] = str;
	}
	return (tmp);
}
