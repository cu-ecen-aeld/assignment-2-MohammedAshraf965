#!/bin/bash

filesdir=$1
searchstr=$2

if [ "$filesdir" ] && [ "$searchstr" ]
then
	echo "The variables were created successfully"
else
	echo "The variables were not created"
	exit 1
fi

if [ -d "$filesdir" ]
then
	echo "The variable links to a directory"
else
	echo "The variable does not link to a directory"
	exit 1
fi

file_count=$(find "$filesdir" -type f | wc -l)
line_count=$(grep -r "$searchstr" "$filesdir" | wc -l)
echo "The number of files are $file_count and the number of matching lines are $line_count"
