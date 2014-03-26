/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:54 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:42:54 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_environment.h"
#include <unistd.h>
#include <stdlib.h>

t_env	*env_unset(char *name, size_t size)
{
	char	**newtab;
	size_t	st;
	t_env	*env;
	size_t	i;

	env = env_singleton();
	i = 0;
	st = (env->m_env) ? ft_tabstrlen(env->m_env) : 0;
	newtab = (env->m_env) ? (char**)ft_memalloc(sizeof(char*) * st) : NULL;
	st = 0;
	while (env->m_env[i])
	{
		if (name == (env->m_env[i] + (size + 1)))
			i++;
		if (env->m_env[i])
		{
			newtab[st] = ft_strdup(env->m_env[i]);
			i++;
			st++;
		}
	}
	newtab[st] = '\0';
	free(env->m_env);
	env->m_env = newtab;
	return (env);
}
