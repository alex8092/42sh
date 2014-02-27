#include "ft_environment.h"
#include "common.h"
#include <stdlib.h>
#include <stdio.h>

extern char	**environ;

static void	env_init(t_env *env)
{
	const int	tab_len = ft_tabstrlen(environ);
	int			index;

	env->m_env = (char **)ft_memalloc(sizeof(char *) * (tab_len + 1));
	index = 0;
	while (index < tab_len)
	{
		env->m_env[index] = environ[index];
		++index;
	}
	env->m_env[index] = 0;
	index = 0;
	while (env->m_env[index])
	{
		printf("env : %s\n", env->m_env[index]);
		++index;
	}
}

t_env		*env_singleton()
{
	static t_env	*env = NULL;

	if (!env)
	{
		env = (t_env *)malloc(sizeof(t_env));
		if (!env)
			exit(1);
		env_init(env);
	}
	return (env);
}
