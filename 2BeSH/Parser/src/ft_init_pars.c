/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:00 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:00 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser_private.h"

t_pars	*p_pars_init(void)
{
	t_pars	*init;

	init = (t_pars*)ft_memalloc(sizeof(t_pars));
	return (init);
}
