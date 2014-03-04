#include "ft_operation.h"
#include "common.h"
#include "stdlib.h"

t_operation		*ft_new_operation(t_operation *parent, t_lex *lex)
{
	t_operation	*new;

	new = (t_operation*)ft_memalloc(sizeof(t_operation));
	if (new == NULL)
		exit (1);
	new->lex = lex;
	if (parent)
		parent->next = new;
	return (new);
}
