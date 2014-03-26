/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:52 by amerle            #+#    #+#             */
/*   Updated: 2014/03/24 11:03:22 by rivers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_private_developement.h"
#include <stdlib.h>

void	ft_creat_chain(char *str, t_dir **cur, t_dir **new_chain, t_file *file)
{
	char	*tmp2;
	t_dir	*new;

	new = NULL;
	tmp2 = NULL;
	tmp2 = ft_strjoin(str, "/");
	new = ft_new_dir(ft_strjoin(tmp2, file->d_name));
	new->delname = true;
	free(tmp2);
	if (!*cur)
	{
		*cur = new;
		*new_chain = *cur;
	}
	else
	{
		(*cur)->next = new;
		*cur = (*cur)->next;
	}
}

int		ft_read_dir(t_dir **cur, char *str, t_dir **new_chain)
{
	DIR		*directory;
	char	*str2;
	t_file	*file;

	str2 = NULL;
	directory = NULL;
	file = NULL;
	if ((directory = opendir((*cur)->name)) != NULL)
	{
		str2 = ft_strdup((*cur)->name);
		if ((*cur)->delname)
			free((*cur)->name);
		free(*cur);
		*cur = NULL;
		while ((file = readdir(directory)) != NULL)
		{
			if (ft_matchn(file->d_name, str) > 0 && (file->d_name)[0] != '.')
				ft_creat_chain(str2, cur, new_chain, file);
		}
		free(str2);
		closedir(directory);
		return (1);
	}
	return (0);
}

void	ft_add_chain_dir(t_dir **prev, t_dir **chain, t_dir **dir, t_dir **cur)
{
	if (*prev)
		(*prev)->next = *chain;
	else
		*dir = *chain;
	*prev = *cur;
}

void	ft_delete_dir(t_dir **prev, t_dir **next, t_dir **dir, t_dir *cur)
{
	if (cur->delname)
		free(cur->name);
	free(cur);
	if (*prev)
		(*prev)->next = *next;
	else
		*dir = *next;
}
