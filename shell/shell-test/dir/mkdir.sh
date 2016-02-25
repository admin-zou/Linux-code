#! /bin/bash

function is_dir()
{
	loacl dir-$1
	if [ -d ${dir} ] ; then
			return 0 #already exit
	else
			return 1
	fi
}

for dir in $@
do
		if is_dir ${dir};then
				:
		else
				echo "${dir} doesn't exit, create it!"
				mkdir ${dir} > /dev/null 2>&1
				if [ $? -ne 0 ];then
						echo "create ${dir} failed!"
						exit 1
				fi
		fi
done

