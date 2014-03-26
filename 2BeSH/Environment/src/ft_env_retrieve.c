/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_retrieve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 06:33:49 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 06:36:01 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_environment.h"
#include <pwd.h>

void	p_env_retrieve(void)
{
	t_env			*env;
	struct passwd	*pw;

	env = env_singleton();
	if (!env->get("USER"))
		env->set("USER", getlogin());
	if (!env->get("PWD"))
	{
		env->set("PWD", getcwd(NULL, 0));
		env->set("OLDPWD", getcwd(NULL, 0));
	}
	if (!env->get("PATH"))
		p_env_retrieve_path();
	if (!env->get("TERM"))
		env->set("TERM", "xterm");
	if (!env->get("HOME"))
	{
		pw = getpwuid(getuid());
		env->set("HOME", pw->pw_dir);
	}
	env->set("CLICOLOR", "1");
}
