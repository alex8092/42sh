#ifndef FT_BUILDINS_PRIVATE_H
# define FT_BUILDINS_PRIVATE_H

# include "ft_buildins.h"

struct		s_buildin
{
	char		*name;
	void		(*exec)(char **argv);
	t_buildin	*next;
};

void		p_buildins_cd(char **argv);
void		p_buildins_echo(char **argv);
void		p_buildins_exit(char **argv);
void		p_buildins_env(char **argv);
void		p_buildins_setenv(char **argv);
void		p_buildins_unsetenv(char **argv);
void		p_buildins_test_amerle(char **argv);
t_buildin	*p_buildins_new(t_buildin *p, char *name, void (*f)(char **argv));
void		p_buildins_init_builds(t_buildins *bi);

#endif
