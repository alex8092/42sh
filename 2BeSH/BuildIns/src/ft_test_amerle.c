/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_amerle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:21 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 10:03:18 by rivers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins_private.h"
#include "ft_resolver.h"
#include <stdio.h>

int		p_buildins_test_amerle(char **arg)
{
	printf("result : %s\n", ft_resolv_path("~"));
	(void)arg;
	return (0);
}
