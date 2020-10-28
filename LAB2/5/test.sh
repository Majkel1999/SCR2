#!/bin/bash
sleep 5
for i in $(seq 1 8);
do
	kill -$i $1
	echo "kill $i $1"
	sleep 1
done
for i in $(seq 10 15);
do
	kill -$i $1
	echo "kill $i $1"
	sleep 1
done
kill -9 $1

