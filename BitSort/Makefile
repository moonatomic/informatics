build: main.o bitSort.o countBits.o fillData.o isSorted.o output.o bin.o copyData.o compare.o buildHeap.o headers.h 
	gcc $^
	make clean
main.o: main.c
	gcc -c $^
bitSort.o: bitSort.c
	gcc -c $^
countBits.o: countBits.c
	gcc -c $^
fillData.o: fillData.c
	gcc -c $^
isSorted.o: isSorted.c
	gcc -c $^
output.o: output.c
	gcc -c $^
bin.o: bin.c
	gcc -c $^
copyData.o: copyData.c
	gcc -c $^
compare.o: compare.c
	gcc -c $^
buildHeap.o: buildHeap.c
	gcc -c $^
clean:
	rm *.o
	rm *.gch