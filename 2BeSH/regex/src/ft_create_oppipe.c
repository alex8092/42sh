/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_oppipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:02 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:02 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"

t_oppipe	*ft_create_oppipe(t_regbuilder *rb)
{
	t_oppipe	*pipe;

	pipe = (t_oppipe *)ft_new_reg(rb->end, REGOP_PIPE, sizeof(t_oppipe));
	if (pipe)
	{
		pipe->type_pipe = 0;
		++rb->pos;
		rb->end = (t_regex *)pipe;
	}
	return (pipe);
}
