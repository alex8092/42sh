#include "ft_operation.h"
#include "ft_security.h"
#include "common.h"
#include "stdlib.h"

t_operation		*ft_new_operation(t_operation *parent, t_lex *lex)
{
	t_operation	*new;

	new = (t_operation*)ft_memalloc(sizeof(t_operation));
	if (new == NULL)
		security_singleton()->critical("malloc");
	new->lex = lex;
	if (parent)
		parent->next = new;
	return (new);
}
