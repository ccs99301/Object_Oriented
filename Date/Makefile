all: Date main
	g++ main.o Date.o -o main

Date: Date.cpp Date.h
	g++ -c Date.cpp

main: main.cpp Date.h Date.cpp
	g++ -c main.cpp

clean:
	rm -f *.o main
