all: main.o 
	clang++ -g -Wall -std=c++11 main.o -o main

main.o: main.cpp calculations.hpp roof-and-fence-constants.hpp
	clang++ -g -Wall -std=c++11 -c main.cpp

clean:
	rm -f *.o main
