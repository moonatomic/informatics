build: main.o bin.o power.o reverse.o headers.h
	gcc $^
	make clean
main.o: main.c
	gcc -c $^
bin.o: bin.c
	gcc -c $^
power.o: power.c
	gcc -c $^
reverse.o: reverse.c
	gcc -c $^
clean:
	rm *.gch *.o