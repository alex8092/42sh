/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:03 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:03 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"
#include <unistd.h>

t_regex	*ft_regex(char *str)
{
	t_regbuilder	rb;

	rb.str = str;
	rb.pos = 0;
	rb.begin = NULL;
	rb.end = NULL;
	rb.escape = false;
	ft_regex_parse(&rb);
	return (rb.begin);
}
