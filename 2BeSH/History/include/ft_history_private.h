#ifndef FT_HISTORY_PRIVATE_H
# define FT_HISTORY_PRIVATE_H

# include "ft_history.h"
# include "common.h"

struct	s_lst_history
{
	char				*cmd;
	t_lst_history		*prev;
	t_lst_history		*next;
};

int			p_history_size(void);

void		p_history_init_attributes(t_history *history);
void		p_history_init_methods(t_history *history);

#endif
