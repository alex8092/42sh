/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 08:43:11 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 08:44:12 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_private.h"

int			p_prompt_size(void)
{
	return (prompt_singleton()->m_size);
}