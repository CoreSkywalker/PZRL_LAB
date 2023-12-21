reqso = main.o oct.o hex.o bin.o -lm

.PHONY: all clean run
all: a.out
clean:
	rm a.out *.o
run: a.out
	./a.out
main.o: main.c
	gcc main.c -c
hex.o: hex.c
	gcc hex.c -c -lm
oct.o: oct.c
	gcc oct.c -c -lm
bin.o: bin.c
	gcc bin.c -c -lm
a.out: $(reqso)
	gcc $(reqso)
