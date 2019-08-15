#!/bin/bash

echo 'Enter number: '
read number

if (($number % 2)); then
    echo 'Odd'
else
    echo 'Even'

fi

