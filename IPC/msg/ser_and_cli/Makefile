#1 多文件编译
BIN_SER=ser
BIN_CLI=cli
SRC_SER=msg_ser.c comm.c
SRC_CLI=msg_cli.c comm.c
CC=gcc
FLAGS=-g
INCLUDE=-I.

.PHONY:all
all:$(BIN_SER) $(BIN_CLI)

$(BIN_SER):$(SRC_SER)
	$(CC) -o $@ $^ $(FLAGS) $(INCLUDE)

$(BIN_CLI):$(SRC_CLI)
	$(CC) -o $@ $^ $(FLAGS) $(INCLUDE)

.PHONY:clean
clean:
	rm $(BIN_SER) $(BIN_CLI)


##2. 使用静态库时的Makefile
#
#BIN_SER=ser
#BIN_CLI=cli
#SRC_SER=msg_ser.c
#SRC_CLI=msg_cli.c
#CC=gcc
#FLAGS=-g -D_DEBUG_
#INCLUDE=-L. -lcomm -I.
#
#.PHONY:all
#all:$(BIN_SER) $(BIN_CLI)
#
#$(BIN_SER):$(SRC_SER)
#	$(CC) -o $@ $^ $(FLAGS) $(INCLUDE)
#
#$(BIN_CLI):$(SRC_CLI)
#	$(CC) -o $@ $^ $(FLAGS) $(INCLUDE)
#
#.PHONY:clean
#clean:
#	rm $(BIN_SER) $(BIN_CLI)
