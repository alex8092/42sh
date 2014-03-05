#include "ft_resolver.h"

void	ft_resolv_redirects(t_operation *op, t_lex **begin)
{
	t_lex	*cur;
	t_lex	*last;

	cur = *begin;
	last = NULL;
	while (cur)
	{
		if (cur->op == LEX_OP_REDIRECT_OUT && cur->next)
			op->s_fd_out = cur->next->str;
		else if (cur->op == LEX_OP_REDIRECT_IN && cur->next)
			op->s_fd_in = cur->next->str;
		else if (cur->op == LEX_OP_APPEND_OUT && cur->next)
		{
			op->s_fd_out = cur->next->str;
			op->append_out = true;
		}
		else
		{
			last = cur;
			cur = cur->next;
			continue ;
		}
		if (last)
		{
			last->next = cur->next->next;
			cur = last->next;
		}
	}
}
