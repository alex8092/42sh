/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_security_private.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:13 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:13 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SECURITY_PRIVATE_H
# define FT_SECURITY_PRIVATE_H

# include "ft_security.h"

void		p_security_init_attributes(t_security *security);
void		p_security_init_methodes(t_security *security);
void		p_security_init_signal(void);
void		p_security_exit_critical(char *error);

t_security	*p_security_active_raw(t_bool active);

#endif
