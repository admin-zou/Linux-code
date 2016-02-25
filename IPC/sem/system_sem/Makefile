BIN=libsemlock.a
SRC=sem_lock.o
PSRC=sem_lock.c
CC=ar
PCC=gcc
$(BIN):$(SRC)
	$(CC) -rc $(BIN) $(SRC)
$(SRC):$(PSRC)
	$(PCC) -c $(PSRC)

.PHONY:clean
clean:
	rm $(SRC) semlib -rf
.PHONY:out
out:
	mkdir semlib
	cp libsemlock.a semlib
	cp sem_lock.h semlib	
