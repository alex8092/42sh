/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:32 by amerle            #+#    #+#             */
/*   Updated: 2014/03/27 21:40:27 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMMON_H
# define FT_COMMON_H

# include <unistd.h>

enum	e_bool { true = 1, false = 0 };

typedef enum e_bool	t_bool;

t_bool	ft_isprint(unsigned char c);
t_bool	ft_isinarray(char c, char *ref);

size_t	ft_strlen(const char *str);

char	*ft_strndup(char *src, int nb);
char	*ft_strdup(char *str);
char	*ft_strjoin(const char *str, const char *str2);
char	*ft_strchr(const char *s, int c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strtrim(char const *s);
char	*ft_itoa(int number);
char	**ft_strsplit(char *str, char separator, t_bool escape);
char	**ft_tabstradd(char **tab, char *str);

int		ft_tabstrlen(char **tab);
int		ft_findfirstof(char *str, char *ref);
int		ft_strncmp(char *str, char *str2, size_t n);
int		ft_strcmp(char *str, char *str2);
int		ft_atoi(char const *number);
int		ft_matchn(char *s1, char *s2);

void	ft_bzero(void *ptr, int size);
void	*ft_memalloc(int size);
void	ft_memcpy(void *dest, const void *src, size_t size);
void	ft_memdel(void **ap);
void	ft_strdel(char **ap);
void	ft_putchar_fd(int fd, char c);
void	ft_putstr_fd(int fd, char const *str);
void	ft_putnbr_fd(int fd, long nbr);
void	ft_tabstrdel(char **tab);
t_bool	ft_getnextline(int fd, char **line);

#endif

