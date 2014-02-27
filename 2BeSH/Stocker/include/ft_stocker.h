#ifndef FT_STOCKER_H
# define FT_STOCKER_H

# include "common.h"

typedef struct s_lst_stocker		t_lst_stocker;
typedef struct s_stocker			t_stocker;

struct	s_stocker
{
	t_lst_stocker		*m_start;
	t_lst_stocker		*m_end;
	int					m_length;

	int					(*size)(void);

	t_stocker			*(*push_back)(char c);
	t_stocker			*(*push_front)(char c);

	t_stocker			*(*rm_back)(void);
	t_stocker			*(*rm_front)(void);

	char				*(*to_string)(void);
};

t_stocker	*stocker_singleton();

#endif
