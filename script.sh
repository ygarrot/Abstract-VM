#!/bin/bash
if [ -f .log ]; then
	echo "rm .log"
	rm .log
fi

for file in `find test -type f`
do
	echo $file >>.log
	trap `./vm $file 2>>.log >>.log` 6
done
