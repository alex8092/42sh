/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 07:20:58 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 19:10:02 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_private.h"
#include <ft/regex.h>
#include "ft_environment.h"
#include <stdio.h>
#include <stdlib.h>

static int	count_offset(char *str)
{
	int		count;
	t_bool	escape;

	count = 0;
	escape = false;
	while (*str)
	{
		if (!escape && *str == 27)
		{
			escape = true;
			++count;
		}
		else if (escape && *str != 'm')
			++count;
		else if (escape)
		{
			escape = false;
			++count;
		}
		++str;
	}
	return (count);
}

char		*p_prompt_string(void)
{
	static t_regex	*reg = NULL;
	static t_regex	*reg2 = NULL;
	t_regex			*reg3;
	char			*str;
	char			*tmp;

	reg = !reg ? ft_regex("\\\\u") : reg;
	reg2 = !reg2 ? ft_regex("\\\\w") : reg2;
	str = env_singleton()->get("HOME");
	reg3 = str ? ft_regex(str) : NULL;
	str = prompt_singleton()->m_prompt;
	str = ft_regmatch_replace(str, reg, env_singleton()->get("USER"));
	tmp = str;
	str = ft_regmatch_replace(str, reg2, env_singleton()->get("PWD"));
	if (tmp != str)
		free(tmp);
	tmp = str;
	if (reg3)
		if ((str = ft_regmatch_replace_all(str, reg3, "~")) != tmp)
			free(tmp);
	prompt_singleton()->m_size = ft_strlen(str) - count_offset(str);
	if (reg3)
		ft_regex_free(reg3);
	return (str);
}
