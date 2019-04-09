all: Bag main
	g++ main.o Bag.o -o main.exe

Bag: Bag.cpp Bag.h
	g++ -c Bag.cpp

main: main.cpp Bag.h Bag.cpp
	g++ -c main.cpp

clean: 
	-rm *.o main.exe
