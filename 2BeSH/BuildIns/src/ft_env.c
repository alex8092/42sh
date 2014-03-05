#include "ft_buildins_private.h"
#include "ft_environment.h"
#include "common.h"
#include "ft_display.h"

static t_bool	ft_check_flag(char *str)
{
	int		index;

	index = 1;
	if (str[index] == '-')
	{
		while (str[index])
		{
			if (str[index] != 'i' || str[index] != 'u')
				return (false);
			index++;
		}
		return (true);
	}
	return (false);
}

static void 	ft_put_env_error(char *str)
{
	write(2, "env: ", 5);
	write(2, str, ft_strlen(str));
	write(2, " bad argument\n", 15);
}

void			p_buildins_env(char **arg)
{
	const t_env	*env = env_singleton();
	size_t		i;

	i = 0;
	if (arg[1])
	{
		if (arg[1][0] == '-')
		{
			while (ft_check_flag(arg[i]))
				i++;
			write (1, "exec env -i\n", 12);
		}
		else
			ft_put_env_error(arg[1]);
	}
	else
	{
		while (env->m_env[i])
		{
			display_singleton()->putstr(env->m_env[i]);
			display_singleton()->putstr("\n");
				++i;
		}
	}
}
