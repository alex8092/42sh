/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meth_lex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:52 by amerle            #+#    #+#             */
/*   Updated: 2014/03/27 20:35:03 by thrivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_private_developement.h"
#include <stdlib.h>
#include "ft_environment.h"

void		ft_clear_lex(t_lex *begin)
{
	t_lex	*tmp;

	tmp = NULL;
	if (begin)
	{
		tmp = begin->next;
		while (tmp)
		{
			free(begin);
			begin = tmp;
			if (tmp->next)
				tmp = tmp->next;
		}
	}
}

int			put_lex(t_lex **cur, t_lex **tmp2, t_lex *(fct(t_lex *cur)))
{
	t_lex	*tmp;

	tmp = NULL;
	tmp = (*cur)->next;
	(*cur)->next = NULL;
	*cur = fct(*cur);
	if (*cur)
	{
		(*tmp2)->next = *cur;
		while ((*cur)->next)
			*cur = (*cur)->next;
	}
	else
	{
		(*tmp2)->next = tmp;
		(*cur) = tmp;
		return (0);
	}
	(*cur)->next = tmp;
	return (1);
}

void		ft_concat_match(t_lex **cur, t_lex **beg, t_file *file, t_dir *dir)
{
	char	*tmp;
	char	*tmp2;
	int		i;
	int		y;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_strjoin(dir->name, "/");
	tmp2 = ft_strjoin(tmp, file->d_name);
	i = ft_strlen(env_singleton()->get("PWD"));
	y = ft_strlen(tmp2);
	if (y > i)
	{
		if (!ft_strncmp(tmp2, env_singleton()->get("PWD"), i))
		{
			tmp = ft_strdup(tmp2 + i + 1);
			free(tmp2);
			tmp2 = ft_strdup(tmp);
			free(tmp);
		}
	}
	*cur = new_lex(cur, beg, tmp2);
	free(tmp2);
}

t_lex		*new_lex(t_lex **cur, t_lex **begin, char *str)
{
	t_lex	*new;

	new = NULL;
	new = ft_memalloc(sizeof(t_lex));
	new->op = 2;
	new->str = ft_strdup(str);
	if (*cur)
	{
		(*cur)->next = new;
		*cur = (*cur)->next;
	}
	else
	{
		*cur = new;
		*begin = *cur;
	}
	return (*cur);
}
