build: main.o countBits.o power.o headers.h
	gcc $^
	make clean
main.o: main.c
	gcc -c $^
countBits.o: countBits.c
	gcc -c $^
power.o: power.c
	gcc -c $^
clean:
	rm *.o *.gch