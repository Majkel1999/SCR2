#!/bin/bash

$arr
while read line; do
	arr+="$line "
done < <(find -name "*.$1" -mtime -"$2")

tar -cvf $3.tar $arr
