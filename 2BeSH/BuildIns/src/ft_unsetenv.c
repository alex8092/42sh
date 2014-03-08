#include "ft_buildins_private.h"
#include "ft_environment.h"
#include "common.h"
#include <stdio.h>

void	p_buildins_unsetenv(char **argv)
{
	size_t	size;
	char	*name;
	size_t	i;

	i = 1;
	if (argv[i])
	{
		while (argv[i])
		{
			size = ft_strlen(argv[i]);
			name = env_singleton()->get(argv[i]);
			if (name && ft_strcmp(argv[i], "PATH")
				&& ft_strcmp(argv[i], "USER")
				&& ft_strcmp(argv[i], "PWD") && ft_strcmp(argv[i], "OLDPWD"))
				env_singleton()->unset(name, size);
			i++;
		}
	}
	else
		write(2, "unsetenv: Too few arguments\n", 28);
}
