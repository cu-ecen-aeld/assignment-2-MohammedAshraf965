#!/bin/bash

writefile=$1
writestr=$2

if [ "$writefile" ] && [ "$writestr" ]
then
	echo "The variables were created successfully"
else
	echo "The variables were not created"
	exit 1
fi

touch $writefile

if [ -e "$writefile" ]
then
	echo "The file was created successfully"
	echo "$writestr" >> "$writefile"
else
	echo "The file was not created"
	exit 1
fi
