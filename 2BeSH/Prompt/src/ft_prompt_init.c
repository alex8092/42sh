/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:23 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 19:14:53 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_private.h"

void	p_prompt_init_attributes(t_prompt *prompt)
{
	char	*s;

	s = ".: \033[1;36m2BeShell\033[0m :. \033[1;34m\\u\033[0m"
		" [\033[0;33m\\w\033[0m] ~> ";
	prompt->m_prompt = s;
	prompt->m_size = ft_strlen(prompt->m_prompt);
}

void	p_prompt_init_methodes(t_prompt *prompt)
{
	prompt->size = p_prompt_size;
	prompt->to_string = p_prompt_string;
}
