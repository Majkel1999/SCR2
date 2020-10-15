#!/bin/bash

data=$(LC_ALL=C date);

data=$(echo $data | awk '{print $1;}');

if [ $data == "Sun" -o $data == "Sat" ] ; then
	echo "Mamy weekend, mozna odpoczac!";
else 
	echo "Jest dzien roboczy, trzeba isc do pracy";
fi
