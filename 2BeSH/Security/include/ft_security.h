/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_security.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 17:59:13 by amerle            #+#    #+#             */
/*   Updated: 2014/02/17 18:41:05 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SECURITY_H
# define FT_SECURITY_H

# include "common.h"

typedef struct s_security	t_security;

struct	s_security
{
	t_security	*(*activeRaw)(t_bool);
};

t_security	*security_singleton();

#endif
