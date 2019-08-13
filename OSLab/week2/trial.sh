#!/bin/bash

#echo $HOME, $PATH
#echo $MAIL

#firstname=Virat
#lastname=Kohli

#echo $firstname $lastname
#export lastname

#echo $1 $2

#echo $lastname

#echo Enter name:
#read name

#echo Your name is $name

#password=Virat
#readonly password

#echo $password
#read password

message=Hello
echo $message

echo "the program $0 is now running"
echo "the 2nd argument was $2"
echo "the 1st argument was $1"
echo "your home directory is $HOME"
echo "enter new greeting"
read greeting
echo $greeting

echo "$0 execution complete"
exit 0