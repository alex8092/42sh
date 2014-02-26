#ifndef FT_STOCKER_PRIVATE_H
# define FT_STOCKER_PRIVATE_H

# include "ft_stocker.h"

struct	s_lst_stocker
{
	char				c;
	t_lst_stocker	*prev;
	t_lst_stocker	*next;
};

t_lst_stocker	*p_stocker_new_lst();
t_lst_stocker	*p_stocker_new_lst_el(char c);

void			p_stocker_add_back_lst(char c);
void			p_stocker_add_front_lst(char c);

#endif
