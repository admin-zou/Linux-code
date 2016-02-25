#!/bin/bash

g_file=file						#字符串剪切
while read line
do
part1=$(echo $line | cut -c 1-3)						  #从1到3剪切出来
part2=$(echo $line | cut -c 4-6 | tr '[a-z]	' '[A-Z]')	  #将a-z 转化为大写
part3=$(echo $line | cut -c 7-9)						  #从7到9剪切

echo "${part1}${part2}${part3}"							  #逆置
#echo "${part3}${part2}${part1}">>log  #追加重定向
	#echo $line
	#sleep 1
done<file >log
#done<${g_file}
