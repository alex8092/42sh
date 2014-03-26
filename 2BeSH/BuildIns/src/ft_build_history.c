/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:37:48 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:46:40 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins.h"
#include "ft_history_private.h"
#include <stdio.h>

static void	print(int *i, t_bool prev, int add)
{
	char	*str;

	str = NULL;
	if (prev)
	{
		history_singleton()->m_current = history_singleton()->m_current->prev;
		if (history_singleton()->m_current)
			str = history_singleton()->m_current->cmd;
	}
	else
	{
		history_singleton()->m_current = history_singleton()->m_current->next;
		if (history_singleton()->m_current)
			str = history_singleton()->m_current->cmd;
	}
	if (str)
	{
		ft_putchar_fd(1, '\t');
		ft_putnbr_fd(1, (long)(*i + 1 + add));
		ft_putchar_fd(1, '\t');
		ft_putstr_fd(1, str);
		ft_putstr_fd(1, "\n");
	}
	++(*i);
}

static void	display_superior(int size)
{
	int	i;

	if (size == 0 || size > history_singleton()->size())
		size = history_singleton()->size();
	i = 0;
	while (i < size)
		print(&i, false, 0);
}

static void	display_inferior(int size)
{
	int	i;

	if (size == 0 || -size > history_singleton()->size())
		size = history_singleton()->size();
	history_singleton()->m_current = history_singleton()->m_end;
	size = -size;
	i = 0;
	while (i < size)
	{
		history_singleton()->m_current = history_singleton()->m_current->prev;
		++i;
	}
	i = 0;
	while (i < size)
		print(&i, false, history_singleton()->size() - size);
}

int			p_buildins_history(char **argv)
{
	int	size;

	size = 0;
	if (argv)
	{
		if (*(argv + 1) && !*(argv + 2))
			size = ft_atoi(*(argv + 1));
		else if (*(argv + 1) && *(argv + 2))
		{
			ft_putstr_fd(2, "2BeSH : too many arguments\n");
			return (1);
		}
		history_singleton()->m_current = history_singleton()->m_start;
		if (history_singleton()->m_current && size < 0)
			display_inferior(size);
		else if (history_singleton()->m_current)
			display_superior(size);
		history_singleton()->m_current = 0;
	}
	return (0);
}
