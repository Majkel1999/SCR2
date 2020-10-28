#!/bin/bash
sleep 5
echo "Wysylam SIGSTOP o $(date +"%T")"
kill -19 $1;
sleep 5
echo "Wysylam SIGCONT o $(date +"%T")"
kill -18 $1;
sleep 5
kill -9 $1


