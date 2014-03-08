#include "ft_resolver.h"
#include "ft_regex.h"
#include "ft_environment.h"
#include <stdlib.h>

static char	*ft_resolv_path_do(char *str, int begin)
{
	char	*res;

	res = ft_strdup(str);
	if (begin)
	{
		if (str[ft_strlen(str) - 1] != '/')
			res = ft_strjoin(str, "/");
	}
	else
	{
		if (str[ft_strlen(str) - 1] == '/')
			res = ft_strndup(str, ft_strlen(str) - 1);
	}
	return (res);
}

char	*ft_resolv_path(char *str)
{
	static t_regex	*reg_tilde = NULL;
	static t_regex	*reg_curdir = NULL;
	static t_regex	*reg_prev = NULL;
	static t_regex	*reg_prev_end = NULL;
	char			*tmp;
	char			*res;

	if (!reg_tilde)
		reg_tilde = ft_regex("^~");
	if (!reg_curdir)
		reg_curdir = ft_regex("^\\./");
	if (!reg_prev)
		reg_prev = ft_regex("/[^/]{1,}/\\.\\./");
	if (!reg_prev_end)
		reg_prev_end = ft_regex("/[^/]{1,}/\\.\\.$");
	tmp = env_singleton()->get("HOME");
	res = NULL;
	str = ft_resolv_path_do(str, 1);
	if (tmp)
		res = ft_regmatch_replace_all(str, reg_tilde, tmp);
	tmp = ft_strjoin(env_singleton()->get("PWD"), "/");
	res = (res) ? res : str;
	res = ft_regmatch_replace_all(res, reg_curdir, tmp);
	free(tmp);
	tmp = res;
	while ((res = ft_regmatch_replace(tmp, reg_prev, "/")))
	{
		free(tmp);
		tmp = res;
	}
	ft_regmatch_replace_all(tmp, reg_prev_end, "/");
	tmp = ft_resolv_path_do(tmp, 0);
	return (tmp);
}
