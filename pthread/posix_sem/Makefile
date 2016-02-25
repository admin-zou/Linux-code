BIN=pro_consumer
CC=gcc
SRC=ring.c read_write.c

$(BIN):$(SRC)
	$(CC) -o $@ $^ -lpthread

.PHONY:clean
clean:
	rm $(BIN)
