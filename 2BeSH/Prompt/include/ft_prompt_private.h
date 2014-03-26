/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:06 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 19:12:33 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROMPT_PRIVATE_H
# define	FT_PROMPT_PRIVATE_H

# include "ft_prompt.h"

void	p_prompt_init_attributes(t_prompt *prompt);
void	p_prompt_init_methodes(t_prompt *prompt);

int		p_prompt_size(void);

char	*p_prompt_string(void);

#endif
