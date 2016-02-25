.PHONY:all
all:single multiple

single:single_consumer_producer.c  thread_list.c
	gcc -o $@ $^ -I. -lpthread
multiple:multiple_consumer_producer.c thread_list.c
	gcc -o $@ $^ -I. -lpthread

.PHONY:clean
clean:
	rm single mutliple
