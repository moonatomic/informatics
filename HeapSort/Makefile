build: main.o selectionSort.o buildHeap.o isSorted.o fillData.o output.o power.o measureTime.o compare.o heapSort.o headers.h
	gcc $^
	make clean
main.o: main.c
	gcc -c main.c
buildHeap.o: buildHeap.c
	gcc -c buildHeap.c
selectionSort.o: selectionSort.c
	gcc -c selectionSort.c
heapSort.o: heapSort.c
	gcc -c heapSort.c
isSorted.o: isSorted.c
	gcc -c isSorted.c
fillData.o: fillData.c
	gcc -c fillData.c
output.o: output.c
	gcc -c output.c
power.o: power.c
	gcc -c power.c
measureTime.o: measureTime.c
	gcc -c measureTime.c
compare.o: compare.c
	gcc -c compare.c
clean:
	rm *.o
	rm *.gch

