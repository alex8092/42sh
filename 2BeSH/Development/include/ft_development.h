#ifndef FT_DEVELOPMENT_H
# define FT_DEVELOPMENT_H

typedef struct s_development	t_development;

struct		s_development
{
	char	*(*start)(char *base);
};

t_development	*dev_singleton();

#endif
