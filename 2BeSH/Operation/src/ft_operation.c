#include "ft_operation.h"
#include "stdlib.h"

t_operation		*ft_init_operation(void)
{
	t_operation	*op;

	if (!op)
	{
		op = (t_operation*)malloc(sizeof(t_operation));
		if (op == NULL)
			exit (1);
		op->next = NULL;
	}
	return (op);
}
