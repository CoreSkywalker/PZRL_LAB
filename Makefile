reqsc = main.c bin.c oct.c hex.c -lm
reqso = main.c oct.o hex.o bin.o -lm

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
