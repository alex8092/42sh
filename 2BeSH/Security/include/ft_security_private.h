#ifndef FT_SECURTY_PRIVATE_H
# define FT_SECURTY_PRIVATE_H

# include "ft_security.h"

void		p_security_init_attributes(t_security *security);
void		p_security_init_methodes(t_security *security);
void		p_security_exit_critical(char *error);

t_security	*p_security_active_raw(t_bool active);

#endif
