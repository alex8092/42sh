/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:06 by amerle            #+#    #+#             */
/*   Updated: 2014/03/27 20:03:56 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_validator.h"
#include "ft_environment.h"
#include "ft_display.h"
#include "ft_executor.h"
#include <stdlib.h>

static t_bool	concat_path(char *path, t_operation *op)
{
	char	*tmp;

	if (path[ft_strlen(path) - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		free(path);
	}
	else
		tmp = path;
	path = ft_strjoin(tmp, op->lex->str);
	free(tmp);
	if (access(path, F_OK) != -1 && access(path, X_OK) != -1)
	{
		op->exec_file = path;
		return (true);
	}
	free(path);
	return (false);
}

static t_bool	is_abs_ok(t_operation *op)
{
	if (access(op->lex->str, F_OK) != -1)
	{
		if (access(op->lex->str, X_OK) != -1)
		{
			op->exec_file = ft_strdup(op->lex->str);
			return (true);
		}
		else
			ft_putstr_fd(2, "2BeSH : Permission denied [");
	}
	else
		ft_putstr_fd(2, "2BeSH : Executable not found [");
	ft_putstr_fd(2, op->lex->str);
	ft_putstr_fd(2, "]\n");
	return (false);
}

static t_bool	is_valid(t_operation *op)
{
	char	*str;
	char	*last;
	int		index;

	if (op->lex->str[0] == '.' || op->lex->str[0] == '/')
		return (is_abs_ok(op));
	if ((str = env_singleton()->get("PATH")) && (ASSIGN(last, str)))
	{
		while ((index = ft_findfirstof(last, ":")) != -1)
		{
			if (concat_path(ft_strndup(last, index), op))
				return (true);
			last += index + 1;
		}
		if ((index = str + ft_strlen(str) - last) > 0)
		{
			if (concat_path(ft_strndup(last, index), op))
				return (true);
		}
	}
	ft_putstr_fd(2, "2BeSh : Command not found [");
	ft_putstr_fd(2, op->lex->str);
	ft_putstr_fd(2, "]\n");
	exec_singleton()->m_status = 1;
	return (false);
}

static void		validator_init(t_validator *val)
{
	val->is_valid = is_valid;
	val->valid_redirects = p_valid_redirects;
	(void)val;
}

t_validator		*validator_singleton(void)
{
	static t_validator	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_validator *)ft_memalloc(sizeof(t_validator));
		validator_init(singleton);
	}
	return (singleton);
}
