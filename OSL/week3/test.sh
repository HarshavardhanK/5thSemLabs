#!/bin/bash

echo "Enter a number"
read num

sum=0

while [ $num -gt 0 ]
do
  x=$((num % 10)) 
  num=$((num / 10))
  sum=$((x + sum))
       
done

echo $sum