#! bin/bash

#case语句
read val
case $val in
	'a')
	echo 'a'
	;;
	'b')
	echo 'b'
	;;
esac



## && || 用于连结两个命令的，-a -o 用于测试两个表达式
##也可用这种风格代替if else
#[ ! -d "dir" ] || {
#	echo "hello dir"
#}
#
#[ ! -f "file" ] || {
#	echo "hello file"
#}




##用这种风格代替if else
#[ -d "dir" ] && {
#	echo "hello dir"
#}
#
#[ -f "file" ] && {
#	echo "hello file"
#}

##if [ : ] #表示恒成立
## if lese 语句 若是空语句，则用：表示
#read sex
#if [ "X${sex}" == "Xboy" ]; then #空格不要忘记 退出碼为0则真，否则为假
#	echo "hello handsome boy" #若此处什么都不做，必须加上：
#elif  [ "X${sex}" == "Xgirl" ]; then
#	echo "hello beautiful girl"
#else
#	echo "sorry"
#fi


#判断
#[ !-d DIR ] 				#加！表示取反
#[ -d DIR1 -a -d DIR2 ] 	#逻辑与操作 -a
#[ -d DIR1 -o -d DIR2 ] 	#逻辑或操作 -o
#read val1
#read val2
#[ ${val}==1 -a ${val2}==2 ]
#	echo $?




#[ -d DIR ] 				# 如果DIR存在并且是一个⽬目录则为真
#[ -f FILE ] 				# 如果FILE存在且是一个普通⽂文件则为真
#[ -z STRING ] 				# 如果STRING的长度为零则为真
#[ -n STRING ] 				# 如果STRING的长度⾮非零则为真
#[ STRING1 = STRING2 ] 		# 如果两个字符串相同则为真
#[ STRING1 != STRING2 ]  	# 如果字符串不相同则为真



#read val  #读变量（输入变量）
#val="boy"
#val="girl"
#val="" # 解析易出错
#[ "X$val" == "Xboy" ]  #左边为空串时被解析为  [ =="boy"]  为了避免空串问题可以两边加上X
#echo $?
#[ "X$val" == "Xgirl" ] # 判断时尽量用==而不用=
#echo $?



#read val
#if test $val -eq 0; then
#		echo "hello boy"
#else
#		echo "hello girl"
#fi

# [] 代替test指令
#read val
##-gt -eq -lt -ge -le #大于 等于 小于 大于等于 小于等于
#[ $val -eq 10 ]
#echo $?
#[ $val -lt 10 ]
#echo $?
#[ $val -le 10 ]
#echo $?
#[ $val -gt 10 ]
#echo $?
#[ $val -ge 10 ]
#echo $?

#read val
##-gt -eq -lt -ge -le #大于 等于 小于 大于等于 小于等于
#test $val -eq 10
#echo $?
#test $val -lt 10
#echo $?
#test $val -le 10
#echo $?
#test $val -gt 10
#echo $?


#val=100
#区别
#echo 'hello world,${val},`date`,'\\''
#echo "hello world,${val},`date`,'\\',"



#prog=$(basename $0)
#
#echo "${prog} parameter list is: $@"
#echo "${prog} parameter count is:$#"
#echo "echo exit code is:@?"
#echo "current process id is:$$"
#
#shift 2
#echo "after shift 2 times:${prog} parameter list is:$@"
#echo "after shift 2 times:${prog} parameter count is:$#"

