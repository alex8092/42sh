/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:39:48 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:48:51 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ft_strncmp(char *str, char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i] && str2[i] && str[i] == str2[i] && i < n)
		++i;
	if (i == n)
		return (0);
	return (str2[i] - str[i]);
}
