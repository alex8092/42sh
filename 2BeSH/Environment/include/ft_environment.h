#ifndef FT_ENVIRONMENT_H
# define FT_ENVIRONMENT_H

typedef struct s_env	t_env;

struct		s_env
{
	char	**m_env;
};

t_env	*env_singleton();

#endif
