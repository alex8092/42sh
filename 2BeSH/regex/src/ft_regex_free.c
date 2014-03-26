/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:58:18 by amerle            #+#    #+#             */
/*   Updated: 2014/03/26 17:58:30 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"
#include <stdlib.h>

void	ft_regex_free(t_regex *regex)
{
	t_regex	*tmp;

	while (regex)
	{
		tmp = regex->next;
		free(regex);
		regex = tmp;
	}
}
