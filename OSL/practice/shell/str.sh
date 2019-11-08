#!/bin/bash

echo "Enter string: "
read string

num=1
num2=3
num3=$((num1 + num2))

if [ -n string ]; then
    printf "Great num is ${num3}\n"
else
    echo "nope"
fi