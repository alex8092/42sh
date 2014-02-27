#ifndef COMMON_H
# define COMMON_H

enum	e_bool { true = 1, false = 0 };
typedef enum e_bool	t_bool;

t_bool	ft_isprint(unsigned char c);
t_bool	ft_isinarray(char c, char *ref);
int		ft_findfirstof(char *str, char *ref);
int		ft_tabstrlen(char **tab);

void	ft_bzero(void *ptr, int size);
void	*ft_memalloc(int size);

#endif

