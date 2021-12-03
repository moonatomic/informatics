build: main.o angle.o cosalpha.o dot.o headers.h length.o root.o arccos.o
	gcc $^
	make clean
main.o: main.c
	gcc -c $^
angle.o: angle.c
	gcc -c $^
cosalpha.o: cosalpha.c
	gcc -c $^
dot.o: dot.c
	gcc -c $^
length.o: length.c
	gcc -c $^
root.o: root.c
	gcc -c $^
arccos.o: arccos.c
	gcc -c $^
clean:
	rm *.gch *.o