#include "ft_buildins_private.h"
#include <stdio.h>
#include <common.h>
#include <stdlib.h>
#include "ft_environment.h"
#include <sys/stat.h>

static void	ft_remplace_pwd(char **pwd, char *remplace)
{
	char	*newpwd;
	char	*tmp;
	int		i;

	printf("pwd %s\n", *pwd);
	i = ft_strlen(*pwd);
	if (remplace)
	{
		tmp = ft_strjoin("/", remplace);
		newpwd = ft_strjoin(*pwd, tmp);
		free(tmp);
	}
	else
	{
		while ((*pwd)[i] != '/' && i > 0)
			i--;
		newpwd = ft_strndup((*pwd), i);
	}
//	free(*pwd);
	printf("new = %s\n", newpwd);
	*pwd = newpwd;
}

static char *ft_find_pwd(char *ptr_env, char *chemin, int i)
{
	char	**tab;
	char	*pwd;

	if (ptr_env && chemin[0] == '/')
		pwd = ft_strdup("/");
	else if (ptr_env)
		pwd = ft_strdup(ptr_env);
	else
		pwd = ft_strdup("");
	tab = ft_strsplit(chemin, '/', false);
	while (tab && tab[i])
	{
		if (!ft_strcmp(tab[i], ".."))
			ft_remplace_pwd(&pwd, NULL);
		else if (!ft_strcmp(tab[i], "."))
			;
		else
			ft_remplace_pwd(&pwd, tab[i]);
		i++;
	}
	return (pwd);
}

static char *ft_find_chemin(char *chemin)
{
	char		*pwd;

	pwd = NULL;
	if (chemin[0] == '-' && !chemin[1])
	{
		if (env_singleton()->get("OLDPWD"))
			pwd = ft_strdup(env_singleton()->get("OLDPWD"));
	}
	else
	{
		if (chemin[0] == '~' && chemin[1] == '/')
			pwd = ft_find_pwd(env_singleton()->get("HOME"), chemin, 1);
		else
		{
			if (chemin[0] == '.' && !chemin[1])
				pwd = ft_find_pwd(env_singleton()->get("PWD"), chemin, 1);
			else
				pwd = ft_find_pwd(env_singleton()->get("PWD"), chemin, 0);
		}
	}
	return (pwd);
}

static void		ft_execute_cd(char *chemin)
{
	char		*pwd;
	struct stat	ptr;
	int			result;


	result = stat(chemin, &ptr);
	if (result > -1)
	{
		result = chdir(chemin);
		if (result == 0 && env_singleton()->get("PWD"))
		{
			pwd = NULL;
			pwd = ft_strdup(env_singleton()->get("PWD"));
			env_singleton()->set("OLDPWD", pwd);
			env_singleton()->set("PWD", chemin);
		}
	}
}

void		p_buildins_cd(char **argv)
{
	char 		*chemin;

	chemin = NULL;
	if (!argv[1])
		chemin = ft_find_chemin("-");
	else if (!argv[2])
		chemin = ft_find_chemin(argv[1]);
	ft_execute_cd(chemin);
}
