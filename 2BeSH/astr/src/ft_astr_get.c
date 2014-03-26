/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astr_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:36:57 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:45:56 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astr_private.h"

char	*p_astr_get(t_astr *astr, size_t index)
{
	if (astr && index < astr->m_size)
		return (astr->m_arr[index]);
	return (NULL);
}
