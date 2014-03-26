/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:39:13 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:48:33 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ft_strcmp(char *str, char *str2)
{
	int	index;

	index = 0;
	while (str[index] && str2[index] && str[index] == str2[index])
		++index;
	return (str2[index] - str[index]);
}
