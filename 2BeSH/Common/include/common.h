#ifndef COMMON_H
# define COMMON_H

# include <unistd.h>

typedef enum e_bool	t_bool;

enum	e_bool { true = 1, false = 0 };

t_bool	ft_isprint(unsigned char c);
t_bool	ft_isinarray(char c, char *ref);

size_t	ft_strlen(char *str);

char	*ft_strndup(char *src, int nb);
char	*ft_strdup(char *str);

char	**ft_strsplit(char *str, char separator, t_bool escape);
char	**ft_tabstradd(char **tab, char *str);

int		ft_tabstrlen(char **tab);
int		ft_findfirstof(char *str, char *ref);
int		ft_strncmp(char *str, char *str2, size_t n);
int		ft_strcmp(char *str, char *str2);

void	ft_bzero(void *ptr, int size);
void	*ft_memalloc(int size);
void	ft_memcpy(void *dest, void * const src, size_t size);

#endif

