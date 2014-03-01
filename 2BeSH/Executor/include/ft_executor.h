#ifndef FT_EXECUTOR_H
# define FT_EXECUTOR_H

# include "ft_operation.h"

typedef struct s_executor	t_executor;

struct		s_executor
{
	void	(*start)(t_operation *);
};

t_executor	*exec_singleton(void);

#endif
