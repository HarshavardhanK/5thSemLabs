#!/bin/bash

lfc=$(ls -alh | wc -l)
afc=$(($lfc-3))
echo "Number of files in the current directory = $afc"