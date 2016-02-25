.PHONY:all
all:select_cli select_ser

select_cli:select_cli.c
	gcc -o $@ $^
select_ser:select_ser.c
	gcc -o $@ $^ -g

.PHONY:clean
clean:
	rm select_cli select_ser
