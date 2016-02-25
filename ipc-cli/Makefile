.PHONY:all
all:cliA cliB
cliA:cliA.c
	gcc -o $@ $^
cliB:cliB.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm cliA cliB
