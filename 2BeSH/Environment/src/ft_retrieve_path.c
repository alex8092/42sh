#include "ft_environment.h"
#include "common.h"
#include <stdio.h>
#include <dirent.h>

static char	*concat_all(char *str, char *str2, char *str3)
{
	char	*res;
	char	*res2;

	res = ft_strjoin(str, str2);
	res2 = ft_strjoin(res, str3);
	free(res);
	return (res2);
}

static void	path_sub(char **res, char *path, int level)
{
	DIR				*d;
	struct dirent	*item;

	d = opendir("/");
	if (!d)
		return ;
	while ((item = readdir(d)))
	{
		if (!ft_strcmp(item->d_name, "bin")
			|| !ft_strcmp(item->d_name, "sbin"))
		{
		}
		else if (level < 3)
			path_sub(res, concat_all(path, "/", item->d_name), level + 1);
	}
	free(path);
	closedir(d);
}

void	p_env_retrieve_path(void)
{
	char	*res;

	res = NULL;
	path_sub(&res, ft_strdup("/"), 0);
}

