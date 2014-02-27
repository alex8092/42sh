#include "ft_environment.h"
#include "common.h"
#include <stdlib.h>
#include <stdio.h>

extern char	**environ;

static char	*env_get(char *name)
{
	int			index;
	const t_env	*env = env_singleton();
	const int	len_str = ft_strlen(name);

	index = 0;
	while (env->m_env[index])
	{
		if (!ft_strncmp(name, env->m_env[index], len_str)
			 && env->m_env[index][len_str] == '=')
			return (env->m_env[index] + len_str + 1);
		++index;
	}
	return (NULL);
}

static size_t	env_size(void)
{
	return (ft_tabstrlen(env_singleton()->m_env));
}

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
	env->get = env_get;
	env->size = env_size;
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
