SER_BIN=shm_ser
CLI_BIN=shm_cli
SER_SRC=comm.c shm_ser.c
CLI_SRC=comm.c shm_cli.c

INCLUDE=-I.
CC=gcc
FLAGS=-g

.PHONY:all
all:$(SER_BIN) $(CLI_BIN)

$(SER_BIN):$(SER_SRC)
	$(CC) -o $@ $^ $(FLAGS) $(INCLUDE)
$(CLI_BIN):$(CLI_SRC)
	$(CC) -o $@ $^ $(FLAGS) $(INCLUDE)

.PHONY:clean
clean:
	rm $(SER_BIN) $(CLI_BIN)
