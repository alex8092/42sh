/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_security.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:13 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 07:02:49 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SECURITY_H
# define FT_SECURITY_H

# include <ft/common.h>

typedef struct s_security	t_security;

struct			s_security
{
	void		(*critical)(char *error);

	t_security	*(*active_raw)(t_bool);
};

t_security		*security_singleton(void);

#endif
