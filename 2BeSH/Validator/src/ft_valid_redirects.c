/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_redirects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:06 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 06:46:36 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_validator.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

static t_bool	p_valid_file(int *fd, char *file, int flag, int right)
{
	struct stat		st;

	if (access(file, F_OK) != -1)
	{
		if (access(file, R_OK) != -1 && stat(file, &st) != -1)
		{
			if (!S_ISDIR(st.st_mode))
			{
				if (right != 0)
					(*fd) = open(file, flag, right);
				else
					(*fd) = open(file, flag);
				return (*fd != -1);
			}
			else
				ft_putstr_fd(2, "error: Is a directory\n");
		}
		else
			ft_putstr_fd(2, "error: No right\n");
		return (false);
	}
	(*fd) = (right) ? open(file, flag, right) : open(file, flag);
	return (*fd != -1);
}

static t_bool	free_str(char **str)
{
	ft_strdel(str);
	return (false);
}

t_bool			p_valid_redirects(t_operation *op)
{
	int	flag;

	flag = O_WRONLY | O_CREAT;
	if (op->s_fd_out && op->fd_out == -1)
	{
		flag |= (op->append_out) ? O_APPEND : O_TRUNC;
		if (!p_valid_file(&op->fd_out, op->s_fd_out, flag, 0700))
			return (free_str(&op->s_fd_out));
	}
	if (op->s_fd_in && op->fd_in == -1)
	{
		if (!p_valid_file(&op->fd_in, op->s_fd_in, O_RDONLY, 0))
			return (free_str(&op->s_fd_in));
	}
	if (op->s_fd_err && op->fd_err == -1)
	{
		flag |= (op->append_err) ? O_APPEND : O_TRUNC;
		if (!p_valid_file(&op->fd_err, op->s_fd_err, flag, 0700))
			return (free_str(&op->s_fd_err));
	}
	free_str(&op->s_fd_out);
	free_str(&op->s_fd_in);
	if (op->err_to_out)
		op->fd_err = (op->fd_out == -1) ? 1 : op->fd_out;
	return (!free_str(&op->s_fd_err));
}
