#ifndef FT_STOCKER_H
# define FT_STOCKER_H

typedef struct s_lst_stocker		t_lst_stocker;
typedef struct s_stocker			t_stocker;

struct	s_stocker
{
	t_lst_stocker		*m_begin;
	t_lst_stocker		*m_end;

	void				(*add_back)(char c);
	void				(*add_front)(char c);
};

t_stocker	*stocker_singleton();

#endif
