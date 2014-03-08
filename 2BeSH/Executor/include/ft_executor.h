#ifndef FT_EXECUTOR_H
# define FT_EXECUTOR_H

# include "ft_operation.h"

typedef struct s_executor	t_executor;

struct		s_executor
{
	pid_t	m_current;
	void	(*start)(t_operation *);
	pid_t	(*get_current_job)(void);
	void	(*wait_current_job)(void);
};

t_executor	*exec_singleton(void);
int			ft_size_pipes(t_operation *op);
void		ft_exec_pipes(t_operation *op, int size_pipes);
pid_t		p_exec_get_current_job(void);
void		p_exec_wait_current_job(void);

#endif
