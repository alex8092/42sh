/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_security_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:05 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:05 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_security_private.h"

void		p_security_exit_critical(char *error)
{
	ssize_t	ret;

	ret = write(2, error, ft_strlen(error));
	(void)ret;
	security_singleton()->active_raw(false);
	_exit(1);
}
