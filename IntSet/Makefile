all: IntSet main
	g++ main.o IntSet.o -o main

IntSet: IntSet.cpp IntSet.h
	g++ -c IntSet.cpp

main: main.cpp IntSet.h IntSet.cpp
	g++ -c main.cpp

clean:
	rm -f *.o main
