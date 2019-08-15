#!/bin/bash

mkdir H170905022
cd H170905022
mkdir OSLab
cd OSLab
mkdir week1
cd week1

cd ~/H170905022/OSLab/week1
touch file1.txt && touch file2.txt && touch file3.txt
#cd ..
touch file4.txt

#cd week1

touch sort_list.txt
sort sort_list.txt || echo 'error'

cp file1.txt ~/H170905022/OSLab/file4.txt

echo 'getent passwd | wc -l' >> lists.txt 
&& echo 'ls | wc -l ' >> lists.txt

ls a* ls A*

head -5 file1.txt && tail -5 file1.txt
pwd >> file7.txt && date >> file7.txt && ls >> file7.txt