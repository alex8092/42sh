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

t_stocker		*p_stocker_push_back_lst(char c);
t_stocker		*p_stocker_push_front_lst(char c);
t_stocker		*p_stocker_remove_back_lst(void);
t_stocker		*p_stocker_remove_front_lst(void);
t_stocker		*p_stocker_after_current_push(char c);
t_stocker		*p_stocker_current_prev(void);
t_stocker		*p_stocker_current_next(void);

char			*p_stocker_to_string(void);

int				p_stocker_size(void);

void			p_stocker_init_methods(t_stocker *stocker);
void			p_stocker_init_attributes(t_stocker *stocker);

#endif
