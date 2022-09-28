build: main.o headers.hpp library.o
	clang++ -std=c++17 $^
	make clean
	make text
main.o: main.cpp
	clang++ -std=c++17 -c $^
library.o: library.cpp
	clang++ -std=c++17 -c $^
clean:
	rm *.gch
	rm *.o
text: main.cpp headers.hpp library.cpp
	cat main.cpp > main.txt
	cat headers.hpp > headers.txt
	cat library.cpp > library.txt
