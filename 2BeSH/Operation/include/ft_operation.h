#ifndef FT_OPERATION_H
# define FT_OPERATION_H

typedef struct s_operation t_operation;
enum	e_op { OP_PIPE, OP_DBL_PIPE, OP_PV, OP_EP, OP_DBL_EP};
typedef enum e_op	t_op;

struct	s_operation
{
	char			*str;
	t_op			op;
	t_operation		*next;
};

t_operation		*ft_init_operation(void);

#endif
