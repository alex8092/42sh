/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_private_developement.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:11 by amerle            #+#    #+#             */
/*   Updated: 2014/03/27 21:31:22 by thrivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRIVATE_DEVELOPEMENT_H
# define FT_PRIVATE_DEVELOPEMENT_H

# include "ft_development.h"
# include <dirent.h>
# include <sys/types.h>

t_lex	*new_lex(t_lex **cur, t_lex **begin, char *str);
t_lex	*ft_parse_stars(t_lex *begin);
t_lex	*ft_remplace_dollar(t_lex *begin);

int		put_lex(t_lex **cur, t_lex **tm, t_lex *(fct(t_lex *cur)));
int		ft_read_dir(t_dir **cur, char *str, t_dir **new_chain);
int		ft_find_end_dollar(char *str);
int		test3(t_lex **begin, int i, int y);

void	ft_concat_match(t_lex **cur, t_lex **begin, t_file *file, t_dir *dir);
void	ft_add_chain_dir(t_dir **pre, t_dir **chain, t_dir **dir, t_dir **cur);
void	ft_delete_dir(t_dir **prev, t_dir **next, t_dir **dir, t_dir *cur);
void	ft_clear_lex(t_lex *begin);
void	ft_creat_chain(char *str, t_dir **cur, t_dir **chain, t_file *file);
void	ft_find_dollar(t_lex **cur, t_lex **tmp, int i);
void	test(t_lex **begin, char *str, int y);
void	test2(t_lex **begin, char *str, int y, int i);

t_dir	*ft_new_dir(char *str);

#endif
