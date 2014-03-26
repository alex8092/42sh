/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:39:54 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:48:59 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

char	*ft_strndup(char *str, int nb)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char*)malloc(sizeof(char) * (nb + 1));
	if (!dup)
		return (NULL);
	while (i < nb && str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
