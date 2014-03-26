/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findfirstof.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:40 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:47:49 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdio.h>

int	ft_findfirstof(char *str, char *ref)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (ft_isinarray(str[index], ref))
			return (index);
		++index;
	}
	return (-1);
}
