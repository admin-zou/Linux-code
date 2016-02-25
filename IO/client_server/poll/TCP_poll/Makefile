.PHONY:all
all:poll_cli poll_ser
poll_cli:poll_client.c
	gcc -o $@ $^ -g
poll_ser:poll_server.c
	gcc -o $@ $^ -g

.PHONY:clean
clean:
	rm poll_ser poll_cli
