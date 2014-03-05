#include "ft_validator.h"
#include "common.h"
#include "ft_environment.h"
#include <stdlib.h>
#include <stdio.h>

static char		*concat_path(char *path, t_operation *op)
{
	char	*tmp;

	if (path[ft_strlen(path) - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		free(path);
	}
	else
		tmp = path;
	printf("path : %s\n", path);
	path = ft_strjoin(tmp, op->lex->str);
	free(tmp);
	printf("path : %s\n", path);
	free(path);
	return (NULL);
}

static t_bool	is_valid(t_operation *op)
{
	char	*str;
	char	*last;
	int		index;

	str = env_singleton()->get("PATH");
	if (str)
	{
		last = str;
		while ((index = ft_findfirstof(last, ":")) != -1)
		{
			concat_path(ft_strndup(last, index), op);
			last = last + index + 1;
		}
		if ((index = str + ft_strlen(str) - last) > 0)
			concat_path(ft_strndup(last, index), op);
	}
	return (true);
}

static void		validator_init(t_validator *val)
{
	val->is_valid = is_valid;
	(void)val;
}

t_validator	*validator_singleton(void)
{
	static t_validator	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_validator *)ft_memalloc(sizeof(t_validator));
		validator_init(singleton);
	}
	return (singleton);
}
