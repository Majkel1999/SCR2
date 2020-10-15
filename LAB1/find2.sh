#!/bin/bash

while getopts "n:m:a:" options; do
	case "${options}" in
	n)
		old_time=${OPTARG}
		;;
	m)
		mask=${OPTARG}
		;;
	a)
		name=${OPTARG}
		;;
	esac
done

if [ -z "$old_time" ]; then
	if [ -z "$TIME_MASK" ]; then
		echo 'Podaj ilosc dni (w tyl)'
		read old_time;
	else
		old_time=$TIME_MASK
	fi
fi

if [ -z "$mask" ]; then
	if [ -z "$FILETYPE_MASK" ]; then
		echo 'Podaj rozszerzenie pliku'
		read mask;
	else
		mask=$FILETYPE_MASK
	fi
fi

if [ -z "$name" ]; then
	if [ -z "$NAME_MASK" ]; then
		echo 'Podaj nazwe archiwum'
		read name;
	else
		name=$NAME_MASK
	fi
fi

echo find -name "$mask" -mtime -"$old_time"

$arr
while read line; do
	arr+="$line "
done < <(find -name "$mask" -mtime -"$old_time")

tar -cvf $name $arr

