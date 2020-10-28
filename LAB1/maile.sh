#!/bin/bash

file="adresy.txt"

$att
while read line; do
	att+="-A $line "
done < <(find ./ -name "spec*.pdf")

while read line; do
	mail -s "'Zapytanie o oferte'" $att $line < tresc.txt
done < $file



