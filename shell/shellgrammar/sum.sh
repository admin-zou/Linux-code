#!/bin/bash

function sum()
{ #没有用local修饰的全是全局的
	local total=0
	local index=0
	while [ ${index} -le $1 ]
	do
		let total+=$index
		let index++
	done
	echo $total
}

sum 100
