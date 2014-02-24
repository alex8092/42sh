/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 18:45:25 by amerle            #+#    #+#             */
/*   Updated: 2014/02/24 04:19:15 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include "ft_security.h"
#include <stdio.h>

void	end(void)
{
	return ;
}

int		main(int ac, char **av)
{
	security_singleton()->activeRaw(true);
	lexer_singleton()->onComplete(end)->start();
	(void)ac;
	(void)av;
	security_singleton()->activeRaw(false);
	return (0);
}
