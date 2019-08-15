#!/bin/bash

echo "1. Add 2. Sub 3. Multiply 4.Divide"
read choice

read -p 'Enter num1: ' num1
read -p 'Enter num2: ' num2

if [ $choice = 1 ]; then
    echo $((num1 + num2))

elif [ $choice =  2 ]; then
    echo $((num1 - num2))

elif [ $choice = 3 ]; then
    echo $((num1 * num2))

elif [ $choice = 4 ]; then
    echo $((num1 / num2))

else
    echo 'invalid'

fi
