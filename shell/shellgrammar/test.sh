#!/bin/bash



#sum=0
#for val in $@
#do
#	let sum+=val
#	echo $sum
#done

#echo $#
#end=$#
#echo $end
##for val in {1..$end}
#for val in {1..10}
#do
#		echo $val
#done


##函数
#fun()  # 或者 function fun() {}
#{
##	echo $1
##	echo $2
##	echo $3
##	echo $4
##	echo $@
##	echo $#  #若以它作为返回值，为0 
##	echo "a fuction"
#	return 1 #函数返回值
#}
##fun a b c d   #后面的参数是传参
#fun "hehe" "haha" "baibai" "zeze"
#
#echo $? #直接拿到return的返回值,默认为0
#
#ret=$(fun) #或ret=`fun`  先拿到 
#echo "###########################"
#echo $ret  #拿到的是echo出来的值,return出来的值无法拿到
#echo "###########################"






#for val in $# 
#do
#		echo $val
#done


#echo $0       #可执行文件名 
#echo $1 $2    #命令行参数
#echo $#		  #参数个数(不包扩可执行文件名)
#echo $$		  #当前进程id
#echo $!       #紧邻该语句的一个后台进程的id
#echo $@		  #命令行参数列表
#echo $?		  #退出码
#while :
#do
#	:
#done



#count=0
#read passwd
#while [ ! $"X${passwd}" == "Xyes" ]
#do
#	let count++
#	if [ ${count} -gt 5 ];then
#			echo "you have no chance!"
#			exit 
#	fi
#	echo "please Try again"
#	read passwd
#done
#echo "ok!"


##for 死循环
#for ((; ;))
#do
#	echo "hello"
#done
#
##while死循环
#while :
#do
#		echo "world"
#done


#for 类c写法

#for 
#for val in {1..10}
#do
#	sleep 1
#	echo $val
#done

#for 类c写法
#read top
#for (( i=0; i<$top; i++))
#do
#		sleep 1
#		echo $i
#done

##do while  知道条件不满足
#read val
#count=0
#until [ ${count} -ge ${val} ];do
#		echo ${count}
#		let count++
#done

##while
#read count
#index=0
#while [ ${index} -le ${count} ]
#do
#		echo $index
#		#let index++  #或者下面这种方式
#		((index++))
#done




##位置参数
#echo $0 $1 $2 
