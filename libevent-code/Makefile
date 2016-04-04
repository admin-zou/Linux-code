INCLUDE=-I /usr/libevent/include
LIB=-L /usr/libevent/lib/
FLAG=-levent

.PHONY:all
all:tcpserver timeout httpserver

tcpserver:tcpserver.cpp
	g++ -o $@ $^ ${INCLUDE} ${LIB} ${FLAG}

timeout:timeout.c
	gcc -o $@ $^ ${INCLUDE} ${LIB} ${FLAG}

httpserver:httpserver.c
	gcc -o $@ $^ ${INCLUDE} ${LIB} ${FLAG}


.PHONY:clean
clean:
	rm tcpserver
	rm timeout
	rm httpserver
