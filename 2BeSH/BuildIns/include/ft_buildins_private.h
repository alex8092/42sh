#ifndef FT_BUILDINS_PRIVATE_H
# define FT_BUILDINS_PRIVATE_H

# include "ft_buildins.h"

typedef struct s_buildin	t_buildin;

struct		s_buildin
{
	char	*name;
	void	(*exec)(char **argv);
};

void	p_buildins_cd(char **argv);

#endif
