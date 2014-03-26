/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:13 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:56:33 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REGEX_H
# define FT_REGEX_H

# include <ft/common.h>

typedef struct s_regex		t_regex;
typedef enum e_regop		t_regop;

enum	e_regop
{
	REGOP_BASE,
	REGOP_PIPE,
	REGOP_BEG,
	REGOP_END,
	REGOP_BRACK,
	REGOP_REP,
	REGOP_SUB,
	REGOP_ANY
};

struct		s_regex
{
	t_regop	type;
	t_bool	is_rep;
	t_regex	*prev;
	t_regex	*next;
};

t_regex		*ft_regex(char *str);
void		ft_regex_free(t_regex *regex);
char		*ft_regmatch(char *str, t_regex *reg, size_t *len_match);
char		*ft_regmatch_replace(char *str, t_regex *reg, char *repl);
char		*ft_regmatch_replace_all(char *str, t_regex *reg, char *repl);

#endif
