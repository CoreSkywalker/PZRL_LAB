reqso = main.o oct.o hex.o bin.o -lm

.PHONY: all clean run
all: a.out
clean:
	rm a.out *.o
run: a.out
	./a.out
main.o: 
	gcc main.c -c
hex.o:
	gcc hex.c -c -lm
oct.o: 
	gcc oct.c -c -lm
bin.o:
	gcc bin.c -c -lm
a.out: $(reqso)
	gcc $(reqso)
