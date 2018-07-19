#! /bin/bash
if [ "$2" -e "gen" ]; then
	./$1-gen.exe
fi

./$1.exe
./$1-brute.exe
./verify.exe $1-out.txt $1-ans.txt

