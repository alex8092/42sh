#include "ft_buildins_private.h"
#include "ft_environment.h"

void	p_buildins_setenv(char **arg)
{
	char	*param[] = { "env", NULL };

	if (!arg[1])
		p_buildins_env(param);
	else if (!arg[2])
		env_singleton()->set(arg[1], "");
	else if (!arg[3])
		env_singleton()->set(arg[1], arg[2]);
	else
		write(2, "setenv: Too many arguments.\n", 28);
}
