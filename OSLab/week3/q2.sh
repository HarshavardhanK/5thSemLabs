#!/bin/bash

echo 'Enter N: '
read N

i=1
j=0
while [ $j -lt $N ]; do
        printf "${i} "
        i=$(( i + 2 ))
        ((j++))
done

printf "\n"