#!/bin/bash

arr[0]="1"
arr[1]="2"
arr[2]="3"
arr[5]="5"
arr[6]="1"

echo ${arr[@]}		#打印数组
echo ${#arr[@]} 	#统计数组的元素的个数
echo ${arr[7]}		#可以访问
echo ${arr[8]}		#可以访问


#arr=("hehe" "haha" "zeze")
#echo ${arr[@]}
#echo ${arr[2]}
#echo ${#arr[@]}
#
#arr[0]="kiding"
#
#for val in ${arr[@]}
#do
#		echo ${val}_bit   #可以加后缀
#done
#
#
#
#index=0
#while [ $index -lt ${#arr[@]} ]
#do 
#	echo ${arr[$index]}_bit
#	let index++
#	#((index++))
#	# ??? index = `expr $index + 1`
#done
#
#
#
#arr=('1' '2' '3' '4' '5')
#echo ${arr[@]}  #打印数组的全部内容
#echo ${arr[0]}
#echo ${arr[1]} 
#echo ${arr[2]}
#echo ${arr[3]}
#echo ${arr[4]}

