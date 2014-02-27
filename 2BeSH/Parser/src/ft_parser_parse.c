#include "ft_parser_private.h"
#include "common.h"
#include "ft_operation.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	p_parser_parse(char *str)
{
	int			i;
	char		*tmp;
	t_operation	*cmd_op;
	t_operation	*begin;

	tmp = str;
	cmd_op = ft_init_operation();
	begin = cmd_op;
	while ((i = ft_findfirstof(tmp, ";|&")) != -1)
	{
		if (tmp[i] == ';' || tmp[i] == '|' || tmp[i + 1] == tmp[i])
		{
			cmd_op->str = ft_strndup(str, (i + (tmp - str)));
			if (tmp[i] == tmp[i + 1])
			{
				if (tmp[i] == '|')
					cmd_op->op = OP_DBL_PIPE;
				else
					cmd_op->op = OP_DBL_EP;
				++i;
			}
			else
			{
				if (tmp[i] == ';')
					cmd_op->op = OP_PV;
				else if (tmp[i] == '|')
					cmd_op->op = OP_PIPE;
				else
					cmd_op->op = OP_EP;
			}
			str = tmp + i + 1;
		}
		tmp = tmp + i + 1;
	}
}
