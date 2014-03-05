#include "common.h"
#include "ft_environment.h"
#include <unistd.h>
#include <stdlib.h>



#include <stdio.h>

t_env	*env_unset(char *name, size_t size)
{
	char	**newtab;
	size_t	size_tab;
	t_env	*env;
	size_t	i;

	env = env_singleton();
	i = 0;
	size_tab = (env->m_env) ? ft_tabstrlen(env->m_env) : 0;
	if (env->m_env)
		newtab = (char**)ft_memalloc(sizeof(char*) * size_tab);
	size_tab = 0;
	while (env->m_env[i])
	{
		if (name == (env->m_env[i] + (size + 1)))
			i++;
		newtab[size_tab] = ft_strdup(env->m_env[i]);
		i++;
		size_tab++;
	}
	newtab[size_tab] = '\0';
	free(env->m_env);
	env->m_env = newtab;
	return (env);
}
