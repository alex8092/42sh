#include "ft_parser_private.h"
#include "common.h"
#include "ft_operation.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void		ft_put_dbl_op(char c, t_operation **cmd_op)
{
	if (c == '|')
		(*cmd_op)->op = OP_DBL_PIPE;
	else
		(*cmd_op)->op = OP_DBL_EP;
}

static void		ft_put_single_op(char c, t_operation **cmd_op)
{
	if (c == ';')
		(*cmd_op)->op = OP_PV;
	else if (c == '|')
		(*cmd_op)->op = OP_PIPE;
	else
		(*cmd_op)->op = OP_EP;
}

static void		ft_check_op(char c, char d, t_operation **op)
{
	if (c == d)
		ft_put_dbl_op(c, op);
	else
		ft_put_single_op(c, op);
}

void	 		p_parser_parse(char *str)
{
	int			i;
	char		*tmp;
	t_operation	*cmd_op;
	t_operation	*begin;
	t_operation	*last;

	tmp = str;
	begin = cmd_op;
	while ((i = ft_findfirstof(tmp, ";|&")) != -1)
	{
		cmd_op = ft_init_operation();
		cmd_op->str = ft_strndup(str, (i + (tmp - str)));
		ft_check_op(tmp[i], tmp[i + 1], &cmd_op);
		++i;
		last->next = cmd_op;
		last = cmd_op;
		str = tmp + i + 1;
		tmp = tmp +i + 1;
	}
	last->op = OP_END;
	last->str = ft_strdup(tmp);
}
