#!/bin/sh

while [ -z $1 ];
do
	nc -l 4242 >> ../../debug.log
done
