#!/bin/bash
while true; do
	echo $1 > potok;
	echo "Wyslalem $1";
	sleep 1;
done;
