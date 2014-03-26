/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:12 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 07:35:29 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTOR_H
# define FT_EXECUTOR_H

# include "ft_operation.h"
# include <ft/regex.h>
# include <ft/common.h>
# include <sys/types.h>

# define IF_UNI(X,Y) if (X) Y

typedef struct s_executor	t_executor;

struct		s_executor
{
	pid_t	m_current;
	int		m_status;
	t_bool	m_first;
	void	(*start)(t_operation *);
	pid_t	(*get_current_job)(void);
	void	(*wait_current_job)(void);
	int		(*get_status)(void);
};

t_executor	*exec_singleton(void);
int			ft_size_pipes(t_operation *op);
void		ft_create_pipes(t_operation *cur, int size, int *pipes);
void		ft_close_pipes(int size, int *pipes);
void		ft_apply_dup(t_operation *cur);
pid_t		p_exec_get_current_job(void);
void		p_exec_wait_current_job(void);
int			p_exec_get_status(void);
t_bool		p_ex_build(t_operation *cur, char **tab, t_bool first, pid_t *son);

#endif
