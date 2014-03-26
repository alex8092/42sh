/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_save.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:36:30 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:46:43 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_private.h"

t_display	*p_display_save_cursor(void)
{
	display_singleton()->puts("sc");
	return (display_singleton());
}

t_display	*p_display_restore_cursor(void)
{
	display_singleton()->puts("rc");
	return (display_singleton());
}
