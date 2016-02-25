#!/bin/bash


is_dir()   
{
	dir=$1
	[ -d $dir ] && {    #如果是文件就  return 0
		return 0
	}
	return 1
}


for val in $@
do
		if is_dir ${val} ;then        					# 如果存在了就不创建
				echo "$val is exisit"					
		else
				echo "$val isn't exist,create it!"  	# 如果不存在就创建
				mkdir "$val"
		fi
done
