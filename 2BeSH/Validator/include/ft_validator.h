#ifndef FT_VALIDATOR_H
# define FT_VALIDATOR_H

# include "common.h"
# include "ft_operation.h"

typedef struct s_validator	t_validator;

struct		s_validator
{
	t_bool	(*is_valid)(t_operation *);
};

t_validator	*validator_singleton(void);

#endif
