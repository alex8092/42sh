/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:13 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:13 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_PRIVATE_H
# define FT_PARSER_PRIVATE_H

# include "ft_parser.h"
# include "ft_lexer.h"

typedef enum e_child	t_child;

enum	e_child { RIGHT, LEFT};

t_pars	*p_parser_parse(t_lex *lst);
t_pars	*p_pars_init(void);
t_pars	*p_put_op(t_pars *lst, t_lex *op);
t_lex	*p_find_op(t_lex *lst);

#endif
