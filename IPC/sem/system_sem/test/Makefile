BIN=sem_test
SRC= sem_lock.c sem_test.c
CC=gcc
FLAGS=-g
INCLUDE=-I.

$(BIN):$(SRC)
	$(CC) -o $@ $^ $(FLAGS) $(INCLUDE)

.PHONY:clean
clean:
	rm $(BIN)
