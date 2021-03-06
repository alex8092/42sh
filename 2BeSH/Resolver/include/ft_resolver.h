/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolver.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:13 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:13 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RESOLVER_H
# define FT_RESOLVER_H

# include "ft_operation.h"
# include "ft_parser.h"
# include <ft/common.h>

typedef struct s_resolver	t_resolver;
typedef t_operation	t_resop;

struct		s_resolver
{
	t_lex_op	m_last_op;
	void		(*start)(t_pars *ops);
	char		*(*resolv_path)(char *);
};

t_resolver	*resolver_singleton(void);
void		ft_resolv_redirects(t_operation *op, t_lex **begin);
char		*ft_resolv_path(char *str);
t_lex_op	parse_tr(t_resop **b, t_resop **e, t_pars *t, t_lex_op cur_op);
void		ft_resolv_format(t_operation *op);
char		*ft_resolv_path_force(char *str, char *pwd, t_bool first);
void		resolv_exec(t_resop **b, t_resop **e, t_lex_op cur_op);
void		parse_tr_2(t_resop **b, t_resop **e, t_pars *t, t_lex_op cur_op);
void		parse_tr_3(t_resop **b, t_resop **e, t_pars *t, t_lex *cur);
void		add_op(t_resop **b, t_resop **e, t_pars *t, t_lex_op cur_op);
char		*ft_resolv_bis(char *str, char *pwd, t_bool first);
t_bool		ft_rep_p_cond(t_bool cond, char **str, char *tmp);
char		*ft_resolv_path_do(char *str, int begin, t_bool do_free);

#endif
