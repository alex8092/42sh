#include "ft_environment.h"
#include "common.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

extern char	**environ;

static char		*env_get(char *name)
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

static t_env	*env_set(char *name, char *value)
{
	t_env		*env;
	int			index;
	const int	len_str = ft_strlen(name);
	char		*tmp;

	tmp = ft_strjoin(name, "=");
	env = env_singleton();
	index = 0;
	while (env->m_env[index])
	{
		if (!ft_strncmp(name, env->m_env[index], len_str)
				&& env->m_env[index][len_str] == '=')
		{
			free(env->m_env[index]);
			env->m_env[index] = ft_strjoin(tmp, value);
			free(tmp);
			return (env);
		}
		++index;
	}
	env->m_env = ft_tabstradd(env->m_env, ft_strjoin(tmp, value));
	free(tmp);
	return (env);
}

static size_t	env_size(void)
{
	return (ft_tabstrlen(env_singleton()->m_env));
}

static void		env_init(t_env *env)
{
	const int	tab_len = ft_tabstrlen(environ);
	int			index;

	env->m_env = (char **)ft_memalloc(sizeof(char *) * (tab_len + 1));
	index = 0;
	while (index < tab_len)
	{
		env->m_env[index] = ft_strdup(environ[index]);
		++index;
	}
	env->m_env[index] = 0;
	env->get = env_get;
	env->size = env_size;
	env->set = env_set;
	env->unset = env_unset;
	if (!env->get("USER"))
		env->set("USER", getlogin());
	if (!env->get("PWD"))
		env->set("PWD", getcwd(NULL, 0));
	if (!env->get("OLDPWD"))
		env->set("OLDPWD", getcwd(NULL, 0));
	if (!env->get("PATH"))
		p_env_retrieve_path();
}

t_env		*env_singleton(void)
{
	static t_env	*env = NULL;

	if (!env)
	{
		env = (t_env *)ft_memalloc(sizeof(t_env));
		env_init(env);
	}
	return (env);
}
