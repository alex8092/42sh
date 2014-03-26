/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astr_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:36:54 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:45:52 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astr_private.h"

void	p_astr_free(t_astr **pastr, t_bool del)
{
	if (pastr && *pastr)
	{
		(*pastr)->clear(*pastr, del);
		free(*pastr);
		*pastr = 0;
	}
}
