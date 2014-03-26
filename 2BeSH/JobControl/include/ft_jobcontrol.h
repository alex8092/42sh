/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jobcontrol.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:12 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:12 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_JOBCONTROL_H
# define FT_JOBCONTROL_H

# include <sys/types.h>
# include <termios.h>
# include <ft/common.h>

enum	e_jobstat { JS_BG, JS_STOP, JS_RUN, JS_NO };

typedef struct s_job		t_job;
typedef struct s_jobitem	t_jobitem;
typedef enum e_jobstat		t_jobstat;

struct				s_job
{
	t_jobitem		*begin;
	t_jobitem		*end;
	pid_t			shell_pgid;
	struct termios	shell_modes;
	pid_t			master;
	int				m_size;
	t_bool			stop_master;
	void			(*exit)(int status);
	void			(*add)(pid_t pid, char *str);
	pid_t			(*current)(void);
	t_bool			(*is_active)(void);
	void			(*remove)(pid_t pid);
	int				(*wait)(pid_t pid);
	pid_t			(*get)(int index);
	pid_t			(*get_fg)(void);
	pid_t			(*get_bg)(void);
	void			(*set_bg)(pid_t pid);
	void			(*set_fg)(pid_t pid);
	void			(*print_jobs)(void);
};

struct				s_jobitem
{
	pid_t			pid;
	struct termios	modes;
	char			*str;
	t_jobstat		stat;
	t_bool			stop;
	t_jobitem		*next;
};

t_job				*job_singleton(void);
t_bool				ft_job_is_active(void);
void				ft_job_remove(pid_t pid);
t_bool				ft_job_begin(void);
int					ft_job_wait(pid_t pid);
pid_t				ft_job_get(int index);
pid_t				p_job_get_bg(void);
pid_t				p_job_get_fg(void);
void				p_job_set_bg(pid_t pid);
void				p_job_set_fg(pid_t pid);
void				p_job_print_jobs(void);
void				p_job_exit(int status);

#endif
