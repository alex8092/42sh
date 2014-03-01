#include "ft_buildins_private.h"
#include "ft_environment.h"
#include <stdio.h>

void	p_buildins_env(char **argv)
{
	const t_env	*env = env_singleton();
	size_t		i;

	i = 0;
	while (env->m_env[i])
	{
		write(1, env->m_env[i], ft_strlen(env->m_env[i]));
		write(1, "\n", 1);
		++i;
	}
	(void)argv;
}
