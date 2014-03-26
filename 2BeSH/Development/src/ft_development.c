/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_development.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:52 by amerle            #+#    #+#             */
/*   Updated: 2014/03/26 16:54:13 by thrivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_private_developement.h"
#include "ft_lexer.h"
#include "ft_environment.h"
#include <stdlib.h>
#include "ft_resolver.h"
#include <stdio.h>

int					ft_next(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c == '_')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c >= '9')
		return (1);
	return (0);
}

int					ft_find_end_dollar(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_next(str[i]))
			i++;
		else
			break ;
	}
	return (i);
}

void		test(t_lex **begin, char *str, int y)
{
	char	*tmp2;

	tmp2 = NULL;
	if (y < (int)ft_strlen((*begin)->str))
	{
		tmp2 = ft_strjoin(str, (*begin)->str + y + 1);
		free((*begin)->str);
		(*begin)->str = ft_strdup(tmp2);
		free(tmp2);
	}
	else
	{
		free((*begin)->str);
		(*begin)->str = ft_strdup(str);
	}
}

void		test2(t_lex **begin, char *str, int y, int i)
{
	char	*tmp2;
	char	*tmp;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_strndup((*begin)->str, i);
	tmp2 = ft_strjoin(tmp, str);
	free(tmp);
	tmp = ft_strdup((*begin)->str + y + i + 1);
	free((*begin)->str);
	(*begin)->str = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
}

int		test3(t_lex **begin, int i, int y)
{
	char	*tmp;
	char	*tmp2;

	if (i == 0)
	{
		i = ft_strlen((*begin)->str);
		if (i > (y + 2))
		{
			tmp = ft_strdup((*begin)->str + y + 1);
			free((*begin)->str);
			(*begin)->str = ft_strdup(tmp);
		}
		else
			return (0);
	}
	else
	{
		tmp = ft_strndup((*begin)->str, i);
		tmp2 = ft_strdup((*begin)->str + i + y + 1);
		free((*begin)->str);
		(*begin)->str = ft_strjoin(tmp, tmp2);
		free(tmp2);
	}
	free(tmp);
	return (1);
}

t_lex				*ft_remplace_dollar(t_lex *begin)
{
	int		i;
	int		y;
	char	*str;
	char	*tmp;

	i = ft_findfirstof(begin->str, "$");
	y = ft_find_end_dollar(begin->str + i + 1);
	tmp = ft_strndup(begin->str + i + 1, y);
	if ((str = env_singleton()->get(tmp)))
	{
		if (i == 0)
			test(&begin, str, y);
		else
			test2(&begin, str, y, i);
		free(tmp);
	}
	else
	{
		if (!test3(&begin, i, y))
		{
			ft_clear_lex(begin);
			free(begin);
			return (NULL);
		}
	}
	return (begin);
}

static void			ft_find_dollar(t_lex **cur, t_lex **tmp, int i)
{
	if (i == -1)
		return ;
	else
		put_lex(cur, tmp, ft_remplace_dollar);
}

static t_lex		*ft_resolve(t_lex *current)
{
	char	*tmp;
	int		y;
	int		i;

	tmp = ft_strdup(current->str);
	free(current->str);
	current->str = NULL;
	current->str = ft_resolv_path(tmp);
	free(tmp);
	y = ft_strlen(env_singleton()->get("PWD"));
	i = ft_strlen(current->str);
	if (i != y && !ft_strncmp(current->str, env_singleton()->get("PWD"), y))
	{
		if (y == 1)
			tmp = ft_strdup(current->str + y);
		else
			tmp = ft_strdup(current->str + y + 1);
		free(current->str);
		current->str = ft_strdup(tmp);
		free(tmp);
	}
	return (current);
}

static t_lex		*dev_start(t_lex *begin)
{
	t_lex	*cur;
	t_lex	*tmp2;

	cur = begin->next;
	tmp2 = begin;
	while (cur)
	{
		while (cur && ft_findfirstof(cur->str, "$") > -1)
			ft_find_dollar(&cur, &tmp2, ft_findfirstof(cur->str, "$"));
		if (cur)
		{
			if (ft_findfirstof(cur->str, "*?") > -1 && cur->op != LEX_OP_STR)
			{
				if (!put_lex(&cur, &tmp2, ft_parse_stars))
				{
					ft_putstr_fd(2, ".: error :. No match found\n");
					return (NULL);
				}
			}
			ft_resolve(cur);
			tmp2 = cur;
			cur = cur->next;
		}
	}
	return (begin);
}

static void			ft_dev_init(t_development *dev)
{
	dev->start = dev_start;
	(void)dev;
}

t_development		*dev_singleton(void)
{
	static t_development	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_development*)ft_memalloc(sizeof(t_development));
		ft_dev_init(singleton);
	}
	return (singleton);
}
