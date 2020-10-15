#!/bin/bash
data=$(LC_ALL=C date +'%u')

if [ $data -ge 6 ] ; then
	echo "Jest weekend, mozna odpoczac!";
else
	echo "Jest tydzien, trzeba isc do pracy";
fi

