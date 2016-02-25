BIN=multiple
CC=gcc
SRC=ring.c multiple.c

$(BIN):$(SRC)
	$(CC) -o $@ $^ -g -lpthread

.PHONY:clean
clean:
	rm $(BIN)
