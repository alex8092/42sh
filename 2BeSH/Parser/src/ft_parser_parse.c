#include "ft_parser_private.h"
#include "common.h"
#include "ft_operation.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ft_stocker.h>

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

t_operation	 	*p_parser_parse(char *str)
{
	int			i;
	int			y;
	t_operation	*cmd_op;
	t_operation	*begin;
	t_operation	*last;

	begin = ft_init_operation();
	cmd_op = begin;
	last = NULL;
	i = 0;
	y = 0;
	while ((i = ft_findfirstof((str + y), ";|&")) != -1)
	{
		if (last)
			cmd_op = ft_init_operation();
		if (i != 0)
		{
			cmd_op->str = ft_strndup((str + y), i);
			ft_check_op(str[i + y], str[i + y + 1], &cmd_op);
			if (str[i + y] == str[y + i + 1])
				++i;
			if (last)
				last->next = cmd_op;
			last = cmd_op;
		}
		y += i + 1;
	}
	if (!last)
		last = begin;
	else
		last->next = ft_init_operation();
	last->next->str = ft_strdup(str + y);
	return (begin);
}
