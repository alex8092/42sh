/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:13 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:13 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERATION_H
# define FT_OPERATION_H

# include "ft_lexer.h"
# include <ft/common.h>

typedef struct s_operation	t_operation;
typedef enum e_op			t_op;

enum	e_op { OP_PIPE, OP_DBL_PIPE, OP_PV, OP_EP, OP_DBL_EP, OP_END};

struct				s_operation
{
	t_lex			*lex;
	char			*s_fd_out;
	char			*s_fd_in;
	char			*s_fd_err;
	char			*full_str;
	int				fd_out;
	int				fd_in;
	int				fd_err;
	t_bool			err_to_out;
	char			*exec_file;
	t_bool			append_out;
	t_bool			append_err;
	t_bool			background;
	t_operation		*next;
};

t_operation			*ft_new_operation(t_operation *parent, t_lex *lex);
void				ft_free_op(t_operation *op);

#endif
