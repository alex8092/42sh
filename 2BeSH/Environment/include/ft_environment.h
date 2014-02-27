#ifndef FT_ENVIRONMENT_H
# define FT_ENVIRONMENT_H

# include <unistd.h>

typedef struct s_env	t_env;

struct		s_env
{
	char	**m_env;
	char	*(*get)(char *name);
	size_t	(*size)(void);
};

t_env	*env_singleton();

#endif
