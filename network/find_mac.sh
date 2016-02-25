#!/bin/bash

for i in {1..254}
do
	ip=192.168.0.$i
	ping -c1 ${ip} & >/dev/null &
done

wait

arp -a | grep -v 'imcomplete'
