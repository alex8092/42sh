#include "ft_regex.h"

void	ft_reg_parse_begend(t_reg *reg, t_bool beg)
{
	t_op_begend	*begend;

	begend = (t_op_begend *)ft_reg_create_op(REGOP_BEGEND, reg);
	begend->beg = beg;
	++reg->pos_reg;
}

t_bool	ft_match_begend(t_op_begend *op, t_reg *reg)
{
	if ((op->beg && reg->pos == 0)
		|| (!op->beg && reg->pos == reg->len_b))
		return (true);
	else
		return (false);
}
