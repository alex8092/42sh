#include "ft_regex.h"
#include <stdio.h>

t_bool	ft_match_any(t_op_any *any, t_reg *reg)
{
	t_bool	res;

	(void)any;
	res = false;
	printf("match any : %c {%zu}\n", reg->s_base[reg->pos], reg->pos);
	if (reg->s_base[reg->pos] != '\0')
		res = true;
	if (res)
		++reg->pos;
	return (res);
}

void	ft_reg_parse_slash(t_reg *reg)
{
	if (reg->s_reg[reg->pos_reg + 1] == '\\')
		ft_reg_parse_base(reg);
	else
	{
		printf("escape");
		reg->escape = true;
	}
	++reg->pos_reg;
}

void	ft_reg_parse_any(t_reg *reg)
{
	ft_reg_create_op(REGOP_ANY, reg);
	++reg->pos_reg;
}


