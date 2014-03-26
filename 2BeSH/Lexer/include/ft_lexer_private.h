/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:12 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:12 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_PRIVATE_H
# define FT_LEXER_PRIVATE_H

# include "ft_lexer.h"

struct					s_lex_reg
{
	t_regex				*pattern;
	t_lex_op			op;
	t_lex_reg			*next;
};

void					p_lexer_template_init(t_lexer *lexer);
void					p_lexer_free(t_lex *begin);

#endif
