/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:01 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 19:12:50 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROMPT_H
# define FT_PROMPT_H

# include <ft/common.h>

typedef struct s_prompt	t_prompt;

struct			s_prompt
{
	char	*m_prompt;

	int		m_size;

	char	*(*to_string)(void);
	int		(*size)(void);
};

t_prompt		*prompt_singleton(void);

#endif
