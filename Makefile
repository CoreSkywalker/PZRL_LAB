reqsc = main.c bin.c oct.c hex.c
reqso = main.c oct.o hex.o bin.o

.PHONY: all clean run
all: a.out
clean:
	rm a.out *.o
run: a.out
	./a.out
main.o: $(reqsc)
	gcc -c $(reqsc)
a.out: $(reqso)
	gcc $(reqso)
