#!/bin/bash

bar=''
index=0
pos=0
flag=("|" "/" "-" "\\")

while [ $index -le 100 ]			# 进度条
do
		bar=${bar}#
		let pos=index%4
		sleep 0.1
		printf "[%-100s][%d%%][%c]\r" "${bar}" "$index" "${flag[pos]}";
		((index++))	
done

printf "\n"
