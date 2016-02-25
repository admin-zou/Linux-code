#!/bin/bash

proc=${basename $0}

function usage()
{
	echo "${proc}data1..."
	exit 1
}

[ $# -lt 1 ] && usage

min=$1
max=$1
sum=0;

for val in $@     						#求输入的一串数字中的最大值和最小值
do
		if [ $min -gt $val ];then
			 min=$val
		elif [ $max -lt $val ];then
			 max=$val
		fi
		let sum+=$val
done

echo "min=${min}"
echo "max=${max}"
echo "total=${sum}"

