/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_private_developement.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:52 by amerle            #+#    #+#             */
/*   Updated: 2014/03/27 17:26:19 by thrivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_private_developement.h"
#include "ft_environment.h"
#include "ft_resolver.h"
#include <stdlib.h>

static t_dir	*ft_add_dir(t_dir *begin, char *str)
{
	t_dir	*cur;
	char	*tmp;

	tmp = NULL;
	cur = NULL;
	cur = begin;
	while (cur)
	{
		tmp = ft_resolv_path_force(str, cur->name, 1);
		free(cur->name);
		cur->name = ft_strdup(tmp);
		free(tmp);
		cur = cur->next;
	}
	return (begin);
}

static t_dir	*ft_find_dir(t_dir *dir, char *str)
{
	t_dir	*cur;
	t_dir	*prev;
	t_dir	*next;
	t_dir	*new_chain;

	cur = dir;
	prev = NULL;
	new_chain = NULL;
	next = NULL;
	while (cur)
	{
		next = cur->next;
		if (ft_read_dir(&cur, str, &new_chain))
		{
			ft_add_chain_dir(&prev, &new_chain, &dir, &cur);
			if (cur && cur->next)
				cur->next = next;
		}
		else
			ft_delete_dir(&prev, &next, &dir, cur);
		cur = next;
	}
	return (dir);
}

static char		*ft_parse_arg(t_lex **begin, t_dir **dir)
{
	int		i;
	char	**tab;
	char	*str;

	i = 0;
	str = NULL;
	tab = ft_strsplit((*begin)->str, '/', false);
	while (tab[i + 1])
	{
		if (ft_findfirstof(tab[i], "*?") < 0)
			*dir = ft_add_dir(*dir, tab[i]);
		else
			*dir = ft_find_dir(*dir, tab[i]);
		i++;
	}
	ft_lex_free_item(*begin);
	*begin = NULL;
	str = ft_strdup(tab[i]);
	ft_tabstrdel(tab);
	return (str);
}

static void		ft_find_match(t_dir **dir, char *str, t_lex **cur, t_lex **b)
{
	DIR		*directory;
	t_file	*f;
	t_dir	*tmp3;

	tmp3 = NULL;
	directory = NULL;
	f = NULL;
	while (*dir)
	{
		tmp3 = *dir;
		if ((directory = opendir((*dir)->name)) != NULL)
		{
			while ((f = readdir(directory)) != NULL)
			{
				if (ft_matchn(f->d_name, str) > 0 && (f->d_name)[0] != '.')
					ft_concat_match(cur, b, f, *dir);
			}
			closedir(directory);
		}
		*dir = (*dir)->next;
		if (tmp3->delname)
			free(tmp3->name);
		free(tmp3);
	}
}

t_lex			*ft_parse_stars(t_lex *begin)
{
	t_dir	*dir;
	t_lex	*cur;
	char	*str;

	cur = NULL;
	dir = NULL;
	dir = ft_new_dir(NULL);
	str = ft_parse_arg(&begin, &dir);
	ft_find_match(&dir, str, &cur, &begin);
	free(str);
	return (begin);
}
