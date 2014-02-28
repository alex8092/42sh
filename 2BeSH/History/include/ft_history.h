#ifndef FT_HISTORY_H
# define FT_HISTORY_H

# include "common.h"

typedef struct s_lst_history		t_lst_history;
typedef struct s_history			t_history;

struct	s_history
{
	t_lst_history		*m_start;
	t_lst_history		*m_end;
	t_lst_history		*m_current;

	int					m_length;


	int					(*size)(void);
};

t_history		*history_singleton(void);

#endif
