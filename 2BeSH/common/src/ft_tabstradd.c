/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstradd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:51 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:42:51 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <unistd.h>
#include <stdlib.h>

char	**ft_tabstradd(char **tab, char *str)
{
	char			**newtab;
	size_t			size_tab;

	size_tab = (tab) ? ft_tabstrlen(tab) : 0;
	if (tab)
	{
		newtab = (char **)malloc(sizeof(char *) * (size_tab + 2));
		ft_memcpy(newtab, tab, sizeof(char *) * size_tab);
	}
	else
		newtab = (char **)malloc(sizeof(char *) * 2);
	newtab[size_tab] = str;
	newtab[size_tab + 1] = 0;
	free(tab);
	return (newtab);
}
