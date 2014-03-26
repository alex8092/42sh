/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:37:13 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:46:13 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astr.h"
#include <stdio.h>

int	main(void)
{
	t_astr	*tab;

	tab = ft_astr_create(2);
	tab->set(tab, 0, "bonjour");
	tab->set(tab, 1, "welcome");
	printf("tab : %s\n", tab->get(tab, 0));
	printf("tab : %s\n", tab->get(tab, 1));
	return (0);
}
