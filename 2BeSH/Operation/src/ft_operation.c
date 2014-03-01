#include "ft_operation.h"
#include "common.h"
#include "stdlib.h"

t_operation		*ft_init_operation(void)
{
	t_operation	*op;

	op = (t_operation*)ft_memalloc(sizeof(t_operation));
	if (op == NULL)
		exit (1);
	op->str = NULL;
	op->op = OP_END;
	op->next = NULL;
	return (op);
}
