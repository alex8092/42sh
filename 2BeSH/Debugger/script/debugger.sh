#!/bin/sh

while : ;
do
	if [ ! -z $1 ]; then
		nc -l 4242 >> $1
	else
		nc -l 4242
	fi
done
