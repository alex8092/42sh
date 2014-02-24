/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrivier <thrivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 19:45:52 by thrivier          #+#    #+#             */
/*   Updated: 2014/02/23 19:59:12 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVENT_H
# define FT_EVENT_H

typedef struct s_event	t_event;

struct	s_event
{
	t_event	*(*doEvent)(char *c);
};

t_event	*event_singleton();

#endif
