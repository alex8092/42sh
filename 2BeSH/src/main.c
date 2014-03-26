/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:05 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:05 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include "ft_parser.h"
#include "ft_security.h"
#include "ft_history.h"

int		main(int ac, char **av)
{
	history_singleton()->load();
	security_singleton()->active_raw(true);
	lexer_singleton()->on_complete(parser_singleton()->start)->start();
	(void)ac;
	(void)av;
	security_singleton()->active_raw(false);
	return (0);
}
