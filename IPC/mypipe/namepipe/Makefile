W_BIN=writer
W_SRC=writer.c
R_BIN=reader
R_SRC=reader.c

CC=gcc
FLAG=-g
FIFO=fifo.tmp

.PHONY:all
all: $(W_BIN) $(R_BIN)

$(W_BIN):$(W_SRC)
	$(CC) -o $@ $^ $(FLAG)
$(R_BIN):$(R_SRC)
	$(CC) -o $@ $^ $(FLAG)

.PHONY:clean
clean:
	rm -rf $(W_BIN) $(R_BIN) $(FIFO)
