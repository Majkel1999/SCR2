#!/bin/sh
echo PID $$
trap "echo Sygnal SIGHUP" 1
trap "echo Syngnal SIGINT" 2
trap "echo Sygnal SIGQUIT" 3
trap "echo Sygnal SIGILL" 4
trap "echo Sygnal SIGTRAP" 5

trap "echo Sygnal SIGABRT" 6
trap "echo Sygnal SIGBUS" 7
trap "echo Sygnal SIGFPE" 8
trap "echo Sygnal SIGKILL" 9
trap "echo Sygnal SIGUSR1" 10

trap "echo Sygnal SIGSEGV" 11
trap "echo Syngnal SIGUSR2" 12
trap "echo Sygnal SIGPIPE" 13
trap "echo Sygnal SIGALRM" 14
trap "echo Sygnal SIGTERM" 15

xterm -e ./test.sh $$ -hold &

while true; do
	echo "Jest godzina $(date +"%T")"
	sleep 1
done
