build: main.o selectionSort.o isSorted.o fillData.o output.o power.o measureTime.o compare.o headers.h
	gcc main.o selectionSort.o isSorted.o fillData.o output.o power.o measureTime.o compare.o headers.h
	make clean
main.o: main.c
	gcc -c main.c
selectionSort.o: selectionSort.c
	gcc -c selectionSort.c
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

