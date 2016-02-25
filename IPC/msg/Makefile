BIN=libcomm.a
LBIN=comm.o
SRC=comm.c
CC=ar
LCC=gcc

$(BIN):$(LBIN)
	$(CC) -rc $(BIN) $(LBIN) 
$(LBIN):$(SRC)
	$(LCC) -c $(SRC)

.PHONY:clean
clean:
	rm $(LBIN)

.PHONY:out
out:
	mkdir -p commlib
	cp libcomm.a commlib
	cp comm.h commlib
