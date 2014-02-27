#ifndef FT_STOCKER_H
# define FT_STOCKER_H

typedef struct s_lst_stocker		t_lst_stocker;
typedef struct s_stocker			t_stocker;

struct	s_stocker
{
	t_lst_stocker		*m_start;
	t_lst_stocker		*m_end;
	int					length;

	int					(*size)(void);

	t_stocker			*(*add_back)(char c);
	t_stocker			*(*add_front)(char c);
	t_stocker			*(*to_str)(void);
};

t_stocker	*stocker_singleton();

#endif
