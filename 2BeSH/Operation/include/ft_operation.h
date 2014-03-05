#ifndef FT_OPERATION_H
# define FT_OPERATION_H

# include "ft_lexer.h"

typedef struct s_operation t_operation;
enum	e_op { OP_PIPE, OP_DBL_PIPE, OP_PV, OP_EP, OP_DBL_EP, OP_END};
typedef enum e_op	t_op;

struct	s_operation
{
	t_lex			*lex;
	char			*s_fd_out;
	char			*s_fd_in;
	int				fd_out;
	int				fd_in;
	char			*exec_file;
	t_bool			append_out;
	t_operation		*next;
};

t_operation		*ft_new_operation(t_operation *parent, t_lex *lex);

#endif
