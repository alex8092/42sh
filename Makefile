# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerle <amerle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/17 18:45:33 by amerle            #+#    #+#              #
#    Updated: 2014/02/26 05:59:26 by amerle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C 2BeSH

re:
	make re -C 2BeSH

clean:
	make clean -C 2BeSH

fclean:
	make fclean -C 2BeSH

.PHONY: clean fclean all re
