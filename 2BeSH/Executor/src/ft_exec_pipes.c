#include "ft_executor.h"

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

void	ft_exec_pipes(t_operation *op, int nb_pipes)
{
	(void)op;
	(void)nb_pipes;
}
