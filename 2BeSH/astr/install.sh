# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    install.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/22 05:49:32 by amerle            #+#    #+#              #
#    Updated: 2014/03/22 05:49:32 by amerle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

set -e

PREFIX=/usr

if [ ! -w $PREFIX/lib ] || [ ! -w $PREFIX/include ];
then
	PREFIX=~/.ft
fi

if [ ! -z $4 ] && [ "$4" = "uninstall" ];
then
	echo "Uninstall in prefix : $PREFIX"
	echo "Removing librarys ..."
	rm -f $PREFIX/$1
	echo "Removing includes ..."
	rm -f $PREFIX/$2/astr.h
else
	if [ ! -z $1 ] && [ ! -z $2 ] && [ ! -z $3 ];
	then
		test -e $PREFIX/`dirname $1`/`basename $1` && exit 0
		echo "Install in prefix : $PREFIX"
		echo "Install librarys ..."
		mkdir -p $PREFIX/`dirname $1`
		cp $1 $PREFIX/`dirname $1`
		mkdir -p $PREFIX/$2
		echo "Install includes ..."
		cp $2/astr.h $PREFIX/$2
	fi
fi
