#ifndef FT_EXECUTOR_H
# define FT_EXECUTOR_H

# include "ft_operation.h"

typedef struct s_executor	t_executor;

struct		s_executor
{
	void	(*start)(t_operation *);
};

t_executor	*exec_singleton(void);
int			ft_size_pipes(t_operation *op);
void		ft_exec_pipes(t_operation *op, int size_pipes);

#endif
