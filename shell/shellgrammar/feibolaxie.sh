#!/bin/bash


flag1=1
flag2=1
sum=0
index=2

function Num
{
		if [ $1 == 0 ];then
				echo 0
				return 0
		elif [ $1 == 1 ];then	
			echo 1
			return 1
		fi
		
		while [ $index -le $1 ]
		do
				let sum=`expr $flag1+$flag2`
				let flag1=$flag2
				let flag2=$sum
				let index++
		done
		echo "$sum"
}

Num 100





#arr[0]=1
#arr[1]=1
#
#max=$1
#index=0
#
#while [ $index -le $max ]
#do
#		let arr[$index+2]=arr[$index+1]+arr[index]
#		let index++
#done
#
#echo ${arr[$index-1]}
