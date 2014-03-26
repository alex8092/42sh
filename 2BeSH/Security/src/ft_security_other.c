/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_security_other.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:05 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:05 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_security_private.h"
#include <termios.h>

t_security	*p_security_active_raw(t_bool active)
{
	static struct termios	old;
	static struct termios	new;
	static t_bool			is_active = false;

	if (is_active != active)
	{
		if (active)
		{
			tcgetattr(0, &old);
			new = old;
			new.c_lflag &= ~(ICANON | ECHO);
			tcsetattr(0, TCSANOW, &new);
		}
		else
			tcsetattr(0, TCSANOW, &old);
		is_active = active;
	}
	else if (is_active == active && active)
		tcsetattr(0, TCSANOW, &new);
	return (security_singleton());
}
