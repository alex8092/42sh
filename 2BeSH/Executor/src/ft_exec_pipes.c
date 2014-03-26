/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:55 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 07:10:57 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"
#include <signal.h>

int		ft_size_pipes(t_operation *op)
{
	int	size;

	size = 0;
	while (op)
	{
		++size;
		op = op->next;
	}
	return (size);
}

void	ft_create_pipes(t_operation *cur, int size, int *pipes)
{
	int	i;
	int	tmp;

	i = 0;
	while (size > 1 && i < size)
	{
		tmp = pipe(pipes + i * 2);
		(void)tmp;
		if (cur->next)
			cur->fd_out = pipes[i * 2 + 1];
		if (i != 0)
			cur->fd_in = pipes[i * 2 - 2];
		++i;
		cur = cur->next;
	}
}

void	ft_close_pipes(int size, int *pipes)
{
	int	i;

	i = 0;
	while (size > 1 && i < size)
	{
		close(pipes[i * 2]);
		close(pipes[i * 2 + 1]);
		++i;
	}
}

void	ft_apply_dup(t_operation *cur)
{
	if (cur->fd_out != -1)
		dup2(cur->fd_out, 1);
	if (cur->fd_in != -1)
		dup2(cur->fd_in, 0);
	if (cur->fd_err != -1)
		dup2(cur->fd_err, 2);
}
