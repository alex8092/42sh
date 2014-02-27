#ifndef FT_OPERATION_H
# define FT_OPERATION_H

typedef struct s_operation t_operation;

t_operation
{
	char			*str;
	char			op[2];
	t_operation		*next;
};

#endif
