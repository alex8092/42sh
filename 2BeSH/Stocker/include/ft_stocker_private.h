#ifndef FT_STOCKER_PRIVATE_H
# define FT_STOCKER_PRIVATE_H

# include "ft_stocker.h"
# include "common.h"

struct	s_lst_stocker
{
	char				c;
	t_bool				is_print;
	t_lst_stocker		*prev;
	t_lst_stocker		*next;
};

t_lst_stocker	*p_stocker_new_lst_el(char c);

t_stocker		*p_stocker_add_back_lst(char c);
t_stocker		*p_stocker_add_front_lst(char c);

t_stocker		*p_stocker_add_back_lst(void);
t_stocker		*p_stocker_remove_front_lst(void);


int				p_stocker_size(void);

#endif
