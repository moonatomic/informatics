build: main.o headers.h library.o
	gcc $^
	make clean
	make text
main.o: main.c
	gcc -c $^
library.o: library.c
	gcc -c $^
clean:
	rm *.gch
	rm *.o
text: main.c headers.h library.c
	cat main.c > main.txt
	cat headers.h > headers.txt
	cat library.c > library.txt