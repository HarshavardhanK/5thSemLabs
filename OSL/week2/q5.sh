#!/bin/bash

cat file.txt >> file2.txt
sort file2.txt | uniq -u > file3.txt

#problem with a file we have just received. It has field of fixed length, but no separators.
#The records vary in length with maximum record length being 163 characters
#the records generally appear to appear of the following kind

#L1xxxxxxxxWxAxx
#L3xxxxxxxxABxx

#the first two characters represent record type while the characters
#3-17 represent customer number. Sort the file based on character 3-17, 
#and then based on characters 1-2 to a new file