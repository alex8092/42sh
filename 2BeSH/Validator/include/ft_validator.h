/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:14 by amerle            #+#    #+#             */
/*   Updated: 2014/03/27 20:01:25 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALIDATOR_H
# define FT_VALIDATOR_H

# include <ft/common.h>
# include "ft_operation.h"

# define ASSIGN(X, Y) X = Y

typedef struct s_validator	t_validator;

struct		s_validator
{
	t_bool	(*is_valid)(t_operation *);
	t_bool	(*valid_redirects)(t_operation *);
};

t_validator	*validator_singleton(void);
t_bool		p_valid_redirects(t_operation *op);

#endif
