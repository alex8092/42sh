/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagger_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:56 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 06:41:14 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flagger_private.h"
#include <unistd.h>

static void		print_c_str(t_flag *cur)
{
	ft_putstr_fd(2, "-");
	write(2, &cur->c, 1);
	ft_putstr_fd(2, "|--");
	ft_putstr_fd(2, cur->name);
}

static void		print_c_or_str(t_flag *cur)
{
	if (cur->c)
	{
		ft_putstr_fd(2, "-");
		write(2, &cur->c, 1);
	}
	else
	{
		ft_putstr_fd(2, "--");
		ft_putstr_fd(2, cur->name);
	}
}

static void		print_args(t_flag *cur)
{
	int	index;

	ft_putstr_fd(2, "] ");
	if (!cur->empty)
	{
		if (cur->nb_args == 0)
		{
			index = 0;
			while (index < cur->min_args)
			{
				ft_putstr_fd(2, "arg ");
				++index;
			}
			ft_putstr_fd(2, "[arg]...");
		}
		else
			ft_putstr_fd(2, "arg...");
	}
	ft_putstr_fd(2, "\n");
}

static void		usage(t_flagger *flag)
{
	ft_putstr_fd(2, "usage: ");
	ft_putstr_fd(2, flag->prog_name);
	ft_putstr_fd(2, " [-");
}

void			ft_flagger_print_help(t_flagger *flag)
{
	t_flag	*cur;

	usage(flag);
	cur = flag->m_begin;
	while (cur)
	{
		if (cur->c && !cur->name && cur->empty)
			write(2, &cur->c, 1);
		cur = cur->next;
	}
	ft_putstr_fd(2, "]\n");
	cur = flag->m_begin;
	while (cur)
	{
		if (!(cur->c && !cur->name && cur->empty))
		{
			ft_putstr_fd(2, "       [");
			if (cur->c && cur->name)
				print_c_str(cur);
			else
				print_c_or_str(cur);
			print_args(cur);
		}
		cur = cur->next;
	}
}
