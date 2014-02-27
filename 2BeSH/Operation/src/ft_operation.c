#include "ft_operation.h"

t_operation		*ft_init_operation(void)
{
	t_operation	*op;

	op = (t_operation*)malloc(sizeof(t_operation));
	if (op == NULL)
		exit (1);
	return (op);
}
