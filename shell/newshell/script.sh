#!/bin/bash

##-------------------一个简单脚本
#echo "this is a test"
#cd ..
#ls -l

##-------------------test 与 [ 测试命令
#val=10
#test $val -gt 9
#echo $?
#
#test $val -gt 10
#echo $?
#
#[ $val -gt 9 ]
#echo $?
#
#[ $val -gt 10 ]
#echo $?

##--------------------各种测试命令
#[ -d script.sh ]  #是否是目录
#echo $?
#[ -f script.sh ]  #普通文件
#echo $?
#STRING="" 
#[ -z STRING ]  #string的长度为0则真
#echo $?
#[ -n STRING ] #stirng长度非0则真
#echo $?
#STRING1="haha"
#STRING2="hehe"
#[ STRING1 = STRING2 ] #两字符串长度是否相等
#echo $?
#[ STRING1 != STRING2 ] #两字符串长度不等返回真
#echo $?
#[ ! -d script  ] #非
#echo $?
#[  -n STRING  -a  -z STRING  ] #与
#echo $? 
#[  -n STRING  -o  -z STRING  ] #或
#echo $?


##-----------------------if/else/elif/fi语句
#if [ -d script.sh ];then
#		echo "is dir"
#elif [ -f script.sh ]
#	then
#		echo "is file"
#fi
#
#if : ;then
#		echo "/ is always true"
#fi
#
#echo "please input your id:"
#read id
#echo "please input your password"
#read password
#
#if [ ${id} -eq 1 ];then
#		if [ ${password} -eq 2 ];then
#				echo "you are right"
#		else
#				echo "error"
#		fi
#else
#		echo "try again"
#fi

##---------------------------&& 和 ||
#echo "1+1=?,please enter your answer"
#read val
#[ $val -eq 2 ]&&{
#	echo "well done"
#	exit 0
#}
#echo "you are so fool"
#
#[ ${val} -eq 2 ]||{
#	echo "you are so fool"
#	exit 0
#}
#echo "well done"


##---------------------------case/esac
#read val
#case $val in
#		a)
#		echo "it is a"
#		;;
#		b)
#		echo "it is b"
#		;;
#esac


##----------------------------for
#for i in {a..z}
#do
#		echo "printf val is: $i"
#done
#
#for ((i=0;i<10;i++))
#do
#		echo "print val is:$i"
#done


##----------------------------while
#echo "please enter your username:"
#read name
#while [ ! $name = "tom" ]
#do
#		echo "try again"
#		read name
#done
#
#count=0
#while [ ${count} -lt 10 ]
#do
#		echo "this is :${count}"
#		#((count++))
#		set count=$((count++))
#done


##-----------------------位置参数
#echo "$0 is done"
#echo "$1 is done"
#bash $1 &
#echo "$#"
#echo "$@"
#echo "$$"
#echo "$!"
#echo "$?"
#for val in $@
#do
#		echo "$val"
#done

##----------------------函数
#注意函数体的左花括号{和后面的命令之间必须有空格或换行,如果将最后一条命令和右花括号}写在同一行,命令末尾必须有;号。

fun()
{ 
		bash $1
		echo "$2"
		echo "haha i'am called"
}
fun test.sh 100 


