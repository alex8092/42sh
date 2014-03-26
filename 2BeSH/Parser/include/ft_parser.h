/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:13 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:13 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "ft_lexer.h"
# include <ft/common.h>

typedef struct s_parser	t_parser;
typedef struct s_pars	t_pars;

struct			s_pars
{
	t_lex		*op;
	t_pars		*right;
	t_pars		*left;
	t_pars		*parent;
};

struct			s_parser
{
	void		(*start)(t_lex *begin);
	t_pars		*(*parse)(t_lex*);
};

t_parser		*parser_singleton(void);

#endif
