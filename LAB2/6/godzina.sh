#!/bin/bash

xterm -e ./test.sh $$ &

while true; do
	echo "Jest godzina $(date +"%T")"
	sleep 1
done
