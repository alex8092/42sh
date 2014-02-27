#ifndef COMMON_H
# define COMMON_H

# include <unistd.h>

enum	e_bool { true = 1, false = 0 };
typedef enum e_bool	t_bool;

t_bool	ft_isprint(unsigned char c);
t_bool	ft_isinarray(char c, char *ref);
int		ft_findfirstof(char *str, char *ref);
int		ft_tabstrlen(char **tab);

void	ft_bzero(void *ptr, int size);
void	*ft_memalloc(int size);
int		ft_strncmp(char *str, char *str2, size_t n);
int		ft_strcmp(char *str, char *str2);
size_t	ft_strlen(char *str);

#endif

