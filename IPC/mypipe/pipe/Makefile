BIN=pipe
CC=gcc
FLAG=-g -D_DEBUG
SRC=pipe.c

$(BIN):$(SRC)
	$(CC) -o $@ $^ $(FLAG)
.PHONY:clean
clean:
	rm -rf $(BIN)
